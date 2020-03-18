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
ms.openlocfilehash: 78f6df8286151b61ed026cc6b5170ff3508295d4
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79446886"
---
# <a name="general-project-properties-android-c"></a>Propriedades gerais do projeto (Android C++)

| Propriedade | Descrição | Opções |
|--|--|--|
| Diretório de Saída | Especifica um caminho relativo para o diretório de arquivo de saída e pode incluir variáveis de ambiente. |
| Diretório intermediário | Especifica um caminho relativo para o diretório de arquivo intermediário e pode incluir variáveis de ambiente. |
| Nome do Destino | Especifica um nome de arquivo que este projeto gera. |
| Extensão de destino | Especifica uma extensão de arquivo que este projeto gera. (Exemplo: *.exe* ou *.dll*) |
| Extensões a serem excluídas na limpeza | Especificação de curinga delimitado por ponto e vírgula para os arquivos no diretório intermediário que deverão ser excluídos na limpeza ou na recompilação. |
| Arquivo de log de build | Especifica o arquivo de log de build para gravação quando o registro em log de build está habilitado. |
| Conjunto de ferramentas da plataforma | Especifica o conjunto de ferramentas usado para compilar a configuração atual. Se não estiver definido, o conjunto de ferramentas padrão será usado |
| Tipo de configuração | Especifica o tipo de saída gerado por essa configuração. | **Biblioteca Dinâmica (.so)** – Biblioteca Dinâmica ( *.so*)<br>**Biblioteca estática (.a)** – Biblioteca estática ( *.a*)<br>**Utilitário** – utilitário<br>**Makefile** – Makefile<br> |
| Nível da API de destino | Nível da API do Android NDK de destino dessa configuração. |
| Uso de STL | Especifica qual Biblioteca Padrão C++ deve ser usada para essa configuração. | **biblioteca de runtime C++ mínima (sistema)**<br>**Biblioteca estática de runtime C++ (gabi++_static)**<br>**Biblioteca compartilhada de runtime C++ (gabi++_shared)**<br>**Biblioteca estática de runtime STLport (stlport_static)**<br>**Biblioteca compartilhada de runtime STLport (stlport_shared)**<br>**Biblioteca estática GNU STL (gnustl_static)**<br>**Biblioteca compartilhada GNU STL (gnustl_shared)**<br>**Biblioteca estática LLVM libc++ (c++_static)**<br>**Biblioteca compartilhada LLVM libc++ (c++_shared)**<br> |
| Modo Thumb | Gerar um código que pode ser executado em microarquiteturas thumb. Somente se aplica a arquiteturas arm. | **Thumb**<br>**ARM**<br>**Desabilitado**<br> |
