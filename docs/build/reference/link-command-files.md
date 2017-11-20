---
title: Arquivos de comando LINK | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: link
dev_langs: C++
helpviewer_keywords:
- syntax, LINK command files
- command files [C++]
- LINK tool [C++]
- text files, passing arguments to LINK
- LINK tool [C++], command-line syntax
- command files [C++], LINK
ms.assetid: 7154511c-32b9-4e5b-a515-3922fa9de48e
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 2b6543cbb54dc982b1e55be8c0c554a429410b78
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="link-command-files"></a>Arquivos de comando LINK
Você pode passar argumentos de linha de comando para o LINK na forma de um arquivo de comando. Para especificar um arquivo de comando para o vinculador, use a seguinte sintaxe:  
  
```  
LINK @commandfile  
```  
  
 O `commandfile` é o nome de um arquivo de texto. Nenhum espaço ou tabulação é permitida entre o sinal de arroba (@) e o nome do arquivo. Não há nenhuma extensão padrão; Você deve especificar o nome de arquivo completo, incluindo qualquer extensão. Caracteres curinga não pode ser usada. Você pode especificar um caminho absoluto ou relativo com o nome do arquivo. LINK não usa uma variável de ambiente para pesquisar o arquivo.  
  
 No arquivo de comando, argumentos podem ser separados por tabulações ou espaços (como na linha de comando) e caracteres de nova linha.  
  
 Você pode especificar todos ou parte da linha de comando em um arquivo de comando. Você pode usar mais de um arquivo de comando em um comando LINK. LINK aceita a entrada do arquivo de comando, como se ele tiver sido especificado nesse local na linha de comando. Arquivos de comando não podem ser aninhados. LINK exibe o conteúdo dos arquivos de comando, a menos que o [/NOLOGO](../../build/reference/nologo-suppress-startup-banner-linker.md) opção é especificada.  
  
## <a name="example"></a>Exemplo  
 O comando a seguir para criar uma DLL passa os nomes dos arquivos de objeto e bibliotecas em arquivos separados de comando e usa um terceiro arquivo para a especificação da opção /EXPORTS de comando:  
  
```  
link /dll @objlist.txt @liblist.txt @exports.txt  
```  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)