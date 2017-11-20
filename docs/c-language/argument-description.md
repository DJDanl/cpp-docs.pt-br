---
title: "Descrição do argumento | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- envp argument
- main function, syntax
- arguments [C++], for main function
- argv argument
- argc argument
ms.assetid: 91c2cbe3-9aca-4277-afa1-6137eb8fb704
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 4876d2b05f7124a12976e87022700f9be660b8fc
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="argument-description"></a>Descrição do argumento
O parâmetro `argc` nas funções **main** e **wmain** é um inteiro que especifica quantos argumentos são transmitidos ao programa na linha de comando. Como o nome do programa é considerado um argumento, o valor de `argc` é pelo menos um.  
  
## <a name="remarks"></a>Comentários  
 O parâmetro `argv` é uma matriz de ponteiros para cadeias de caracteres de terminação nula que representam os argumentos do programa. Cada elemento da matriz aponta para uma representação de cadeia de caracteres de um argumento transmitido a **main** (ou a **wmain**). (Para obter informações sobre matrizes, consulte [Declarações de matriz](../c-language/array-declarations.md).) O parâmetro `argv` pode ser declarado como uma matriz de ponteiros para o tipo `char` (`char *argv[]`) ou como um ponteiro para ponteiros para o tipo `char` (`char **argv`). Para **wmain**, o parâmetro `argv` pode ser declarado como uma matriz de ponteiros para o tipo `wchar_t` (`wchar_t *argv[]`) ou como um ponteiro para ponteiros para o tipo `wchar_t` (`wchar_t **argv`).  
  
 Por convenção, `argv`**[0]** é o comando com que o programa é invocado.  No entanto, é possível gerar um processo usando [CreateProcess](http://msdn.microsoft.com/library/windows/desktop/ms682425). Se você usar o primeiro e o segundo argumentos (`lpApplicationName` e `lpCommandLine`), `argv`**[0]** poderá não ser o nome do executável; use [GetModuleFileName](http://msdn.microsoft.com/library/windows/desktop/ms683197) para recuperar o nome do executável.  
  
 O último ponteiro (`argv[argc]`) é **NULL**. (Consulte [getenv](../c-runtime-library/reference/getenv-wgetenv.md) na *Referência da biblioteca em tempo de execução* para conhecer um método alternativo para obter informações sobre a variável de ambiente.)  
  
 **Seção específica da Microsoft**  
  
 O parâmetro `envp` é um ponteiro para uma matriz de cadeias de caracteres de terminação nula que representam os valores definidos nas variáveis de ambiente do usuário. O parâmetro `envp` pode ser declarado como uma matriz de ponteiros para `char` (`char *envp[]`) ou como um ponteiro para ponteiros para `char` (`char **envp`). Em uma função **wmain**, o parâmetro `envp` pode ser declarado como uma matriz de ponteiros para `wchar_t` (`wchar_t *envp[]`) ou como um ponteiro para ponteiros para `wchar_t` (`wchar_t **envp`). O encerramento da matriz é indicado por um ponteiro **NULL** \*. Observe que o bloco de ambiente transmitido para **main** ou **wmain** é uma cópia "congelada" do ambiente atual. Se você alterar subsequentemente o ambiente por meio de uma chamada para _**putenv** ou para `_wputenv`, o ambiente atual (conforme retornado por `getenv`/`_wgetenv` e as variáveis `_environ` ou `_wenviron`) será alterado, mas o bloco para o qual `envp` aponta não será alterado. O parâmetro `envp` é compatível com ANSI em C, mas não em C++.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Função main e execução do programa](../c-language/main-function-and-program-execution.md)