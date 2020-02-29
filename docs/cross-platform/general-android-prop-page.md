---
title: Propriedades gerais do projeto (Android C++)
ms.date: 10/23/2017
ms.assetid: 65f4868b-b864-4989-a275-1e51869ef599
f1_keywords:
- VC.Project.VCConfiguration.Android.OutputDirectory
- VC.Project.VCConfiguration.Android.IntermediateDirectory
- VC.Project.VCConfiguration.Android.TargetName
- VC.Project.VCConfiguration.Android.TargetExt
- VC.Project.VCConfiguration.Android.DeleteExtensionsOnClean
- VC.Project.VCConfiguration.Android.BuildLogFile
- VC.Project.VCConfiguration.Android.PlatformToolset
- VC.Project.VCConfiguration.Android.ConfigurationType
- VC.Project.VCConfiguration.UseOfSTL
- VC.Project.VCConfiguration.ThumbMode
ms.openlocfilehash: 694e69e063f73830c21976bd0615cf4d1d99b368
ms.sourcegitcommit: a673f6a54cc97e3d4cd032b10aa8dce7f0539d39
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/28/2020
ms.locfileid: "78177573"
---
# <a name="general-project-properties-android-c"></a>Propriedades gerais do projeto (Android C++)

Propriedade | DESCRIÇÃO | Opções
--- | ---| ---
Diretório de Saída | Especifica um caminho relativo para o diretório de arquivo de saída e pode incluir variáveis de ambiente.
Diretório intermediário | Especifica um caminho relativo para o diretório de arquivo intermediário e pode incluir variáveis de ambiente.
Nome de destino | Especifica um nome de arquivo que será gerado por este projeto.
Extensão de destino | Especifica uma extensão de arquivo que será gerada por este projeto. (Exemplo: *.exe* ou *.dll*)
Extensões a serem Excluídas na Limpeza | Especificação de curinga delimitado por ponto e vírgula para os arquivos no diretório intermediário que deverão ser excluídos na limpeza ou na recompilação.
Arquivo de log de build | Especifica o arquivo de log de build para gravação quando o registro em log de build está habilitado.
Conjunto de ferramentas da plataforma | Especifica o conjunto de ferramentas utilizado para compilar a configuração atual; se não tiver sido definido, o conjunto de ferramentas padrão é utilizado
Tipo de Configuração | Especifica o tipo de saída gerado por essa configuração. | **Biblioteca Dinâmica (.so)** – Biblioteca Dinâmica ( *.so*)<br>**Biblioteca estática (.a)** – Biblioteca estática ( *.a*)<br>**Utilitário** – utilitário<br>**Makefile** – Makefile<br>
Nível da API de destino | Nível da API do Android NDK de destino dessa configuração.
Uso de STL | Especifica qual Biblioteca Padrão C++ deve ser usada para essa configuração. | **biblioteca de runtime C++ mínima (sistema)**<br>**Biblioteca estática de runtime C++ (gabi++_static)**<br>**Biblioteca compartilhada de runtime C++ (gabi++_shared)**<br>**Biblioteca estática de runtime STLport (stlport_static)**<br>**Biblioteca compartilhada de runtime STLport (stlport_shared)**<br>**Biblioteca estática GNU STL (gnustl_static)**<br>**Biblioteca compartilhada GNU STL (gnustl_shared)**<br>**Biblioteca estática LLVM libc++ (c++_static)**<br>**Biblioteca compartilhada LLVM libc++ (c++_shared)**<br>
Modo Thumb | Gerar um código que pode ser executado em microarquiteturas thumb. Somente se aplica a arquiteturas arm. | **Thumb**<br>**ARM**<br>**Desabilitado**<br>
