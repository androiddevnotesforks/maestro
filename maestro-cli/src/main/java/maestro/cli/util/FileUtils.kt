package maestro.cli.util

import maestro.orchestra.yaml.YamlCommandReader
import maestro.utils.StringUtils.toRegexSafe
import java.io.File
import java.util.zip.ZipInputStream

object FileUtils {

    fun File.isZip(): Boolean {
        return try {
            ZipInputStream(inputStream()).close()
            true
        } catch (ignored: Exception) {
            false
        }
    }

    fun File.isWebFlow(): Boolean {
        if (isDirectory) {
            return listFiles()
                ?.any { 
                    it.getName().matches(".+\\.y[a]?ml".toRegexSafe(RegexOption.IGNORE_CASE)) &&
                    !it.getName().matches("config.y[a]?ml".toRegexSafe(RegexOption.IGNORE_CASE)) &&
                    it.isWebFlow() 
                }
                ?: false
        }

        val config = YamlCommandReader.readConfig(toPath())
        return Regex("http(s?)://").containsMatchIn(config.appId)
    }

}
