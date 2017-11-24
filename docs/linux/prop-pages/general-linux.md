---
title: Propriedades gerais (Projeto do Linux C++) | Microsoft Docs
ms.custom: 
ms.date: 9/26/2017
ms.reviewer: 
ms.suite: 
ms.technology: vs-ide-general
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: 56c800a9-3df9-4196-87b2-81adb00e4767
author: mikeblome
ms.author: mblome
manager: ghogen
f1_keywords:
- VC.Project.VCConfiguration.OutputDirectory
- VC.Project.VCConfiguration.IntermediateDirectory
- VC.Project.VCConfiguration.TargetName
- VC.Project.VCConfiguration.TargetExt
- VC.Project.VCConfiguration.DeleteExtensionsOnClean
- VC.Project.VCConfiguration.PlatformToolset
- VC.Project.VCConfiguration.BuildLogFile
- VC.Project.VCConfiguration.ConfigurationType
- VC.Project.VCConfiguration.UseOfSTL
ms.openlocfilehash: 4de08a00ddedf1eec97d1872646a986e09c22547
ms.sourcegitcommit: ca2f94dfd015e0098a6eaf5c793ec532f1c97de1
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2017
---
# <a name="general-properties-linux-c"></a>Propriedades gerais (Linux C++)

Propriedade | Descrição | Opções
--- | ---| ---
Diretório de Saída | Especifica um caminho relativo para o diretório do arquivo de saída, podendo incluir variáveis de ambiente.
Diretório Intermediário | Especifica um caminho relativo para o diretório de arquivo intermediário, podendo incluir variáveis de ambiente.
Nome de Destino | Especifica um nome de arquivo que este projeto gerará.
Extensão de Destino | Especifica uma extensão de arquivo que este projeto gerará. (Exemplo: .a)
Extensões a serem Excluídas na Limpeza | Especificação de curinga delimitado por ponto e vírgula para quais arquivos no diretório intermediário devem ser excluídos na limpeza ou recompilação.
Arquivo de Log de Build | Especifica o arquivo de log de build para gravação quando o registro em log de build está habilitado.
Conjunto de Ferramentas da Plataforma | Especifica o conjunto de ferramentas utilizado para compilar a configuração atual; se não tiver sido definido, o conjunto de ferramentas padrão é utilizado
Computador de Build Remoto | O computador ou dispositivo de destino a ser usado para build, implantação e depuração remotos.
Diretório Raiz de Build Remoto | Especifica um caminho para um diretório no computador ou dispositivo remoto.
Diretório de Projeto de Build Remoto | Especifica um caminho para um diretório no computador ou dispositivo remoto para o projeto.
Tipo de Configuração | Especifica o tipo de saída gerado por essa configuração. | **Biblioteca Dinâmica (.so)** – Biblioteca Dinâmica (.so)<br>**Biblioteca estática (.a)** – Biblioteca Estática (.a)<br>**Aplicativo (.out)** – Aplicativo (.out)<br>**Makefile** – Makefile<br>
Uso de STL | Especifica qual Biblioteca Padrão C++ deve ser usada para essa configuração. | **Biblioteca C++ Padrão do GNU Compartilhado**<br>**Biblioteca C++ Padrão do GNU Estático (-static)**<br>
