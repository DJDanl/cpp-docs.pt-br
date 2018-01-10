---
title: "Compilando uma biblioteca de importação e exportação de arquivo | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCLibrarianTool.ModuleDefinitionFile
- VC.Project.VCLibrarianTool.ExportNamedFunctions
- VC.Project.VCLibrarianTool.GenerateDebug
- VC.Project.VCLibrarianTool.ForceSymbolReferences
dev_langs: C++
helpviewer_keywords:
- OUT library manager option
- INCLUDE library manager option
- /DEF library manager option
- exporting data
- import libraries, building
- -INCLUDE library manager option
- /OUT library manager option
- DEF library manager option
- -DEF library manager option
- -OUT library manager option
- /INCLUDE library manager option
- -EXPORT library manager option
- exporting data, export (.exp) files
- /EXPORT library manager option
- EXPORT library manager option
- .lib files
- EXP files
ms.assetid: 2fe4f30a-1dd6-4b05-84b5-0752e1dee354
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 979e052147f058e6c46a1c10b1dd89cfd36ee362
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="building-an-import-library-and-export-file"></a>Compilando uma biblioteca de importação e um arquivo de exportação
Para criar uma biblioteca de importação e exportação de arquivo, use a seguinte sintaxe:  
  
```  
LIB /DEF[:deffile] [options] [objfiles] [libraries]  
```  
  
 Quando /DEF for especificado, o LIB cria os arquivos de saída das especificações de exportação que são passadas no comando LIB. Há três métodos para especificar exportações, listadas em ordem de recomendação de uso:  
  
1.  Um **dllexport** definição em um do *objfiles* ou *bibliotecas*  
  
2.  Uma especificação de /EXPORT:*nome* na linha de comando LIB  
  
3.  Uma definição em um **exportações** instrução em um`deffile`  
  
 Esses são os mesmos métodos que você usar para especificar exportações ao vincular um programa de exportação. Um programa pode usar mais de um método. Você pode especificar partes do comando LIB (como vários *objfiles* ou /EXPORT especificações) em um arquivo de comando no comando LIB, assim como você pode em um comando LINK.  
  
 As opções a seguir se aplicam à criação de uma biblioteca de importação e exportação de arquivo:  
  
 / Entrada saída: *importar*  
 Substitui o nome de arquivo de saída padrão para o *importar* biblioteca que está sendo criada. Quando /OUT não for especificado, o nome padrão é o nome base do primeiro arquivo de objeto ou da biblioteca no comando LIB e a extensão. lib. O arquivo de exportação recebe o mesmo nome de base a biblioteca de importação e a extensão. exp.  
  
 /Export: *Nome_da_entrada*[= *internalname*] [, @ `ordinal`[, **NONAME**]] [, **dados**]  
 Exporta uma função em seu programa para permitir que outros programas chamar a função. Você também pode exportar dados (usando o **dados** palavra-chave). Exportações geralmente são definidas em uma DLL.  
  
 O *Nome_da_entrada* é o nome do item de dados ou função como ele será usado pelo programa de chamada. Opcionalmente, você pode especificar o *internalname* como a função conhecida no programa de definição; por padrão, *internalname* é o mesmo que *Nome_da_entrada*. O `ordinal` Especifica um índice para a tabela de exportação no intervalo de 1 a 65.535; se você não especificar `ordinal`, LIB atribui um. O **NONAME** palavra-chave exporta a função apenas como um ordinal, sem um *Nome_da_entrada*. O **dados** palavra-chave é usado para exportar objetos de dados.  
  
 / INCLUEM:`symbol`  
 Adiciona o símbolo especificado para a tabela de símbolos. Essa opção é útil para forçar o uso de um objeto de biblioteca que, caso contrário, não são incluído.  
  
 Observe que se você criar sua biblioteca de importação em uma etapa preliminar, antes de criar o. dll, você deve passar o mesmo conjunto de arquivos de objeto ao criar o arquivo. dll, conforme passado ao criar a biblioteca de importação.  
  
## <a name="see-also"></a>Consulte também  
 [Trabalhando com bibliotecas de importação e arquivos de exportação](../../build/reference/working-with-import-libraries-and-export-files.md)