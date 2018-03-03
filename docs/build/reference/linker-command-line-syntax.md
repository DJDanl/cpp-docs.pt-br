---
title: Sintaxe de linha de comando do vinculador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- linker [C++], syntax
- linker command line [C++]
- LINK tool [C++], command-line syntax
ms.assetid: e2a31e17-77bd-4e74-9305-75b105b26539
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 3ce42aa031b91d5a4ec21ed14ac7cb47643e1325
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-command-line-syntax"></a>Sintaxe da linha de comando do vinculador
Para executar o LINK. EXE, use a seguinte sintaxe de comando:  
  
```  
LINK arguments  
```  
  
 O `arguments` incluem opções e nomes de arquivo e podem ser especificados em qualquer ordem. Opções são processados e, depois, arquivos. Use um ou mais espaços ou guias para separar os argumentos.  
  
> [!NOTE]
>  Você pode iniciar essa ferramenta apenas o [!INCLUDE[vsprvs](../../assembler/masm/includes/vsprvs_md.md)] prompt de comando. Você não pode iniciá-lo em um prompt de comando do sistema ou no Explorador de arquivos.  
  
 Na linha de comando, uma opção consiste em um especificador de opção, um traço (-) ou uma barra invertida (/), seguido do nome da opção. Nomes de opção não podem ser abreviados. Algumas opções têm um argumento, especificado após dois-pontos (:). Nenhum tabulações ou espaços são permitidas dentro de uma especificação de opção, exceto dentro de uma cadeia de caracteres entre aspas na opção /COMMENT. Especifica argumentos numéricos em decimal ou notação de linguagem C. Os nomes de opções e seus argumentos de palavra-chave ou nome de arquivo não diferenciam maiusculas de minúsculas, mas identificadores como argumentos diferenciam maiusculas de minúsculas.  
  
 Para transmitir um arquivo para o vinculador, especifique o nome do arquivo na linha de comando após o comando LINK. Você pode especificar um caminho absoluto ou relativo com o nome do arquivo, e você pode usar curingas no nome de arquivo. Se você omitir a extensão de nome de arquivo e o ponto (.), o LINK pressupõe. obj com a finalidade de localizar o arquivo. LINK não usa extensões de nome de arquivo ou à falta de-los de fazer suposições sobre o conteúdo de arquivos; ele determina o tipo de arquivo por examiná-lo e processa de acordo.  
  
 link.exe retorna zero para o sucesso (sem erros).  Caso contrário, o vinculador retorna o número do erro que interrompeu o link.  Por exemplo, se o vinculador gere LNK1104, o vinculador retorna 1104.  Da mesma forma, o menor número do erro retornado em um erro pelo vinculador é 1000.  Um valor de retorno de 128 representa um problema de configuração com o sistema operacional ou um arquivo. config. o carregador não carrega link.exe ou c2.dll.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)