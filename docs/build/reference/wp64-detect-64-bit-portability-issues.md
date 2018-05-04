---
title: -/Wp64 (detectar problemas de portabilidade de 64 bits) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCCLWCECompilerTool.Detect64BitPortabilityProblems
- VC.Project.VCCLCompilerTool.Detect64BitPortabilityProblems
- /wp64
dev_langs:
- C++
helpviewer_keywords:
- 64-bit compiler [C++], detecting portability problems
- /Wp64 compiler option [C++]
- -Wp64 compiler option [C++]
- Wp64 compiler option [C++]
ms.assetid: 331ae5aa-e627-4d03-8f63-dd2c2d76dadd
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 295f2f690cb3c9db17a410cea1f23d04e54b0054
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="wp64-detect-64-bit-portability-issues"></a>/Wp64 (detectar problemas de portabilidade de 64 bits)

Essa opção de compilador está obsoleta. Nas versões do Visual Studio antes de Visual Studio 2013, isso detecta problemas de portabilidade de 64 bits em tipos que também são marcados com o [w64](../../cpp/w64.md) palavra-chave.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/Wp64  
```  
  
## <a name="remarks"></a>Comentários  

Por padrão, em versões do Visual Studio antes de Visual Studio 2013, o **/Wp64** opção de compilador está desativado no compilador do Visual C++ que cria x86 de 32 bits código, e sobre o compilador do Visual C++ que compila 64 bits, x64 código.  
  
> [!IMPORTANT]
>  O [/Wp64](../../build/reference/wp64-detect-64-bit-portability-issues.md) opção de compilador e [w64](../../cpp/w64.md) palavra-chave foram preteridos no Visual Studio 2010 e o Visual Studio 2012 e não tem suporte a partir do Visual Studio 2013. Se você converter um projeto que usa essa opção, o comutador não será migrado durante a conversão. Para usar essa opção no Visual Studio 2010 ou o Visual Studio 2012, você deve digitar a opção de compilador em **opções adicionais** no **linha de comando** seção de propriedades do projeto. Se você usar o **/Wp64** opção de compilador na linha de comando, o compilador emite D9002 de aviso de linha de comando. Em vez de usar essa opção e a palavra-chave para detectar problemas de portabilidade de 64 bits, use um compilador do Visual C++ que tem como alvo uma plataforma de 64 bits e especifique o [/W4](../../build/reference/compiler-option-warning-level.md) opção. Para obter mais informações, consulte [configurar Visual C++ para x64 de 64 bits, destinos](../../build/configuring-programs-for-64-bit-visual-cpp.md).  
  
Variáveis dos tipos a seguir são testadas em um sistema operacional de 32 bits como se eles estavam sendo usados em um sistema operacional de 64 bits:  
  
-   int  
  
-   long  
  
-   pointer  
  
 Se você regularmente compilar seu aplicativo usando um compilador que cria 64 bits, x64 código, você pode desabilitar apenas **/Wp64** em suas compilações de 32 bits porque o compilador de 64 bits detectará todos os problemas. Para obter mais informações sobre como o sistema operacional Windows de 64 bits de destino, consulte [configurar Visual C++ para x64 de 64 bits, destinos](../../build/configuring-programs-for-64-bit-visual-cpp.md).  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra o projeto **páginas de propriedade** caixa de diálogo.  
  
     Para obter mais informações, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Clique o **C/C++** pasta.  
  
3.  Clique o **linha de comando** página de propriedades.  
  
4.  Modificar o **opções adicionais** caixa para incluir **/Wp64**.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.Detect64BitPortabilityProblems%2A>.  
  
## <a name="see-also"></a>Consulte também  

[Opções do compilador](../../build/reference/compiler-options.md)   
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)   
[Configurar o Visual C++ para destinos x64 de 64 bits](../../build/configuring-programs-for-64-bit-visual-cpp.md)