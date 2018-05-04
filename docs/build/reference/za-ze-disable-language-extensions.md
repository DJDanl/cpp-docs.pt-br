---
title: -Za, - Ze (desabilitar extensões de linguagem) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCCLWCECompilerTool.DisableLanguageExtensions
- /za
- /ze
- VC.Project.VCCLCompilerTool.DisableLanguageExtensions
dev_langs:
- C++
helpviewer_keywords:
- -Za compiler option [C++]
- Za compiler option [C++]
- language extensions, disabling in compiler
- -Ze compiler option [C++]
- language extensions
- enable language extensions
- /Za compiler option [C++]
- /Ze compiler option [C++]
- Disable Language Extensions compiler option
- Ze compiler option [C++]
ms.assetid: 65e49258-7161-4289-a176-7c5c0656b1a2
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2949a3d60af6d9058f02d12aac1fd86dead5affa
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="za-ze-disable-language-extensions"></a>/Za, /Ze (desabilitar extensões de linguagem)
O **/Za** opção de compilador emite um erro para construções de linguagem que não são compatíveis com C89 ANSI ou ISO C++ 11. O **/Ze** opção de compilador, que é ativado por padrão, permite que extensões da Microsoft.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/Za  
/Ze  
```  
  
## <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  O **/Ze** opção é preterida como seu comportamento é ativado por padrão. Recomendamos que você use o [/Zc (conformidade)](../../build/reference/zc-conformance.md) opções do compilador para controlar os recursos de extensão de idioma específico. Para obter uma lista de opções do compilador preterido, consulte o **preteridos e removidos opções do compilador** seção [opções do compilador listadas por categoria](../../build/reference/compiler-options-listed-by-category.md).  
  
 O [!INCLUDE[vcprvc](../../build/includes/vcprvc_md.md)] compilador oferece uma série de recursos além daqueles especificados nos padrões ANSI C89, ISO C99 ou ISO C++. Esses recursos são conhecidos coletivamente como extensões da Microsoft para C e C++. Essas extensões estão disponíveis por padrão e não está disponível quando o **/Za** opção é especificada. Para obter mais informações sobre extensões específicas, consulte [Microsoft Extensions para C e C++](../../build/reference/microsoft-extensions-to-c-and-cpp.md).  
  
 É recomendável desabilitar extensões de linguagem, especificando o **/Za** opção se você planeja porta seu programa em outros ambientes. Quando **/Za** for especificado, o compilador trata Microsoft estendidos palavras-chave como identificadores simples, desabilita extensões do Microsoft e define automaticamente o `__STDC__` macro predefinida para programas do C.  
  
 Usado com outras opções do compilador **/Za** podem afetar como o compilador garante conformidade com os padrões. Por exemplo, **/Za** e [/fp (Especificar comportamento de ponto flutuante)](../../build/reference/fp-specify-floating-point-behavior.md) pode resultar em comportamento de promoção de tipo de ponto flutuante não está de acordo com o ISO C99 ou padrões de 11 C + +.  
  
 Para obter maneiras especificar as configurações de comportamento específico do compatível com padrões, consulte o [/Zc](../../build/reference/zc-conformance.md) opção de compilador.  
  
 Para obter mais informações sobre os problemas de conformidade com [!INCLUDE[vcprvc](../../build/includes/vcprvc_md.md)], consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  No painel de navegação, escolha **propriedades de configuração**, **C/C++**, **idioma**.  
  
3.  Modificar o **desabilitar extensões de linguagem** propriedade.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.DisableLanguageExtensions%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)   
 [/Zc (conformidade)](../../build/reference/zc-conformance.md)