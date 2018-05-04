---
title: -U, -u (Indefinir símbolos) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCCLCompilerTool.UndefinePreprocessorDefinitions
- VC.Project.VCCLWCECompilerTool.UndefinePreprocessorDefinitions
- VC.Project.VCCLCompilerTool.UndefineAllPreprocessorDefinitions
- /u
- VC.Project.VCCLWCECompilerTool.UndefineAllPreprocessorDefinitions
dev_langs:
- C++
helpviewer_keywords:
- -U compiler option [C++]
- Undefine Symbols compiler option
- /U compiler option [C++]
- U compiler option [C++]
ms.assetid: 7bc0474f-6d1f-419b-807d-0d8816763b2a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 897ca229ec7312812b6f2bd2991bf519e98c836c
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="u-u-undefine-symbols"></a>/U, /u (indefinir símbolos)
O **/u** remoções de definições de opção de compilador o símbolo do pré-processador especificado. O **/u** os símbolos específicos da Microsoft que define o compilador de remoções de definição de opção de compilador.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/U[ ]symbol  
/u  
```  
  
## <a name="arguments"></a>Arguments  
 `symbol`  
 O símbolo do pré-processador a exclua.  
  
## <a name="remarks"></a>Comentários  
 Nem o **/u** ou **/u** opção pode cancele um símbolo criado usando o **#define** diretiva.  
  
 O **/u** opção pode cancele um símbolo que foi anteriormente definido usando o **/D** opção.  
  
 Por padrão, o compilador define os seguintes símbolos específicos da Microsoft.  
  
|Símbolo|Função|  
|------------|--------------|  
|CHAR_UNSIGNED|O tipo char padrão é não assinado. Definido quando o [/J](../../build/reference/j-default-char-type-is-unsigned.md) opção é especificada.|  
|CPPRTTI|Definido para o código compilado com o [/GR](../../build/reference/gr-enable-run-time-type-information.md) opção.|  
|CPPUNWIND|Definido para o código compilado com o [/EHsc](../../build/reference/eh-exception-handling-model.md) opção.|  
|DLL|Definido quando o [/MD](../../build/reference/md-mt-ld-use-run-time-library.md) opção é especificada.|  
|M_IX86|Por padrão, definido como 600 para x86 de destinos.|  
|MSC_VER|Para obter mais informações, consulte [Macros predefinidas](../../preprocessor/predefined-macros.md).|  
|WIN32|Definido para aplicativos WIN32. Sempre definido.|  
|_MT|Definido quando o [/MD ou /MT](../../build/reference/md-mt-ld-use-run-time-library.md) opção é especificada.|  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Clique o **C/C++** pasta.  
  
3.  Clique o **avançado** página de propriedades.  
  
4.  Modificar o **exclua definições de pré-processador** ou **cancele todas as definições de pré-processador** propriedades.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.UndefineAllPreprocessorDefinitions%2A> ou <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.UndefinePreprocessorDefinitions%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)   
 [/J (char padrão é de tipo não assinado)](../../build/reference/j-default-char-type-is-unsigned.md)   
 [/GR (Habilitar informações de tipo de tempo de execução)](../../build/reference/gr-enable-run-time-type-information.md)   
 [/EH (modelo de tratamento de exceções)](../../build/reference/eh-exception-handling-model.md)   
 [/MD, /MT, /LD (usar biblioteca de tempo de execução)](../../build/reference/md-mt-ld-use-run-time-library.md)