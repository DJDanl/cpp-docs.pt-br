---
title: -J (char padrão é de tipo não assinado) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-tools
ms.tgt_pltfrm: ''
ms.topic: article
f1_keywords:
- VC.Project.VCCLCompilerTool.DefaultCharIsUnsigned
- VC.Project.VCCLWCECompilerTool.DefaultCharIsUnsigned
- /j
dev_langs:
- C++
helpviewer_keywords:
- defaults, char type
- char data type
- -J compiler option [C++]
- /J compiler option [C++]
- J compiler option [C++]
- default char type is unsigned
ms.assetid: 50973667-6638-491e-9c41-bff73acae19f
caps.latest.revision: 19
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 5195822908c13217244a344357a6140d67a9e7df
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="j-default-char-type-is-unsigned"></a>/J (o tipo char padrão não é assinado)
Altera o padrão de `char` tipo `signed char` para `unsigned char`e o `char` tipo é estendido para zero quando ele será ampliado para um `int` tipo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/J  
```  
  
## <a name="remarks"></a>Comentários  
 Se um `char` valor é declarado explicitamente como `signed`, o **/J** opção não afeta e o valor é de assinatura estendida quando ele será ampliado para um `int` tipo.  
  
 O **/J** opção define `_CHAR_UNSIGNED`, que é usado com `#ifndef` no arquivo Limits. h para definir o intervalo padrão do `char` tipo.  
  
 ANSI C e C++ não requerem uma implementação específica do `char` tipo. Essa opção é útil quando você estiver trabalhando com dados de caractere que eventualmente serão convertidos em um idioma diferente do inglês.  
  
> [!NOTE]
>  Se você usar essa opção de compilador com ATL/MFC, um erro pode ser gerado. Você pode desativar esse erro definindo `_ATL_ALLOW_CHAR_UNSIGNED`, essa solução alternativa não é suportada e não pode funcionar sempre.  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  No **Gerenciador de Soluções**, abra o menu de atalho para o projeto e escolha **Propriedades**.  
  
2.  No projeto **páginas de propriedade** caixa de diálogo, no painel esquerdo, em **propriedades de configuração**, expanda **C/C++** e, em seguida, selecione **delinhadecomando**.  
  
3.  No **opções adicionais** painel, especifique o **/J** opção de compilador.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.DefaultCharIsUnsigned%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)   
 [Trabalhando com Propriedades do Projeto](../../ide/working-with-project-properties.md)