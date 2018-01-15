---
title: -F (Definir tamanho da pilha) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: /f
dev_langs: C++
helpviewer_keywords:
- set stack size compiler option
- F compiler option [C++]
- -F compiler option [C++]
- /F compiler option [C++]
- stack, setting size
ms.assetid: 17320b6f-8305-445b-9ec2-75833f4b29e0
caps.latest.revision: "11"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 5b464a4fb28eb83ef0570416d0cb18fd8f965e0a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="f-set-stack-size"></a>/F (definir tamanho da pilha)
Define o tamanho da pilha de programa em bytes.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/F number  
```  
  
## <a name="arguments"></a>Arguments  
 `number`  
 O tamanho em bytes da pilha.  
  
## <a name="remarks"></a>Comentários  
 Sem essa opção o tamanho da pilha padrão é 1 MB. O `number` argumento pode ser em decimal ou notação de linguagem C. O argumento pode variar de 1 para o tamanho da pilha máximo aceito pelo vinculador. O vinculador Arredonda o valor especificado para os mais próximos 4 bytes. O espaço entre **/F** e `number` é opcional.  
  
 Talvez seja necessário aumentar o tamanho da pilha, se seu programa obtém mensagens de estouro de pilha.  
  
 Você também pode definir o tamanho da pilha:  
  
-   Usando o **/pilha** opção de vinculador. Para obter mais informações, consulte [/pilha](../../build/reference/stack.md).  
  
-   Usando o arquivo .exe EDITBIN. Para obter mais informações, consulte [referência de EDITBIN](../../build/reference/editbin-reference.md).  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Clique o **C/C++** pasta.  
  
3.  Clique o **linha de comando** página de propriedades.  
  
4.  Digite a opção de compilador no **opções adicionais** caixa.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)