---
title: -ZW (compilação de tempo de execução do Windows) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCCLCompilerTool.CompileAsWinRT
- /zw
dev_langs:
- C++
helpviewer_keywords:
- /ZW
- -ZW compiler option
- /ZW compiler option
- -ZW
- Windows Runtime compiler option
ms.assetid: 0fe362b0-9526-498b-96e0-00d7a965a248
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fce6c6825ed4ae715a2f4cde6b0e1ffa8b3b6733
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="zw-windows-runtime-compilation"></a>/ZW (Compilação de Windows Runtime )
Compila o código para oferecer suporte a fonte [!INCLUDE[cppwrt](../../build/reference/includes/cppwrt_md.md)] ([!INCLUDE[cppwrt_short](../../build/reference/includes/cppwrt_short_md.md)]) para a criação de aplicativos Windows UWP (plataforma Universal).  
  
 Quando você usa **/ZW** para compilar, sempre especifique **/EHsc** também.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
/ZW /EHsc  
/ZW:nostdlib /EHsc  
```  
  
## <a name="arguments"></a>Arguments  
 nostdlib  
 Indica que Platform.winmd, Windows.Foundation.winmd e outros arquivos padrão de metadados do Windows (.winmd) não são incluídos automaticamente na compilação. Em vez disso, você deve usar o [/FU (nome forçado #using arquivo)](../../build/reference/fu-name-forced-hash-using-file.md) opção de compilador especificar explicitamente os arquivos de metadados do Windows.  
  
## <a name="remarks"></a>Comentários  
 Quando você especifica o **/ZW** opção, o compilador dá suporte a esses recursos:  
  
-   Arquivos de metadados necessários, namespaces, tipos de dados e funções que seu aplicativo precisa para executar no Windows Runtime.  
  
-   A contagem de referência de objetos de tempo de execução do Windows e o descarte automático de um objeto quando sua contagem de referência chega a zero.  
  
 Como o vinculador incremental não oferece suporte para os metadados do Windows incluído nos arquivos. obj, usando o **/ZW** opção, o [/GM manual (habilitar mínimo recriar)](../../build/reference/gm-enable-minimal-rebuild.md) opção é incompatível com **/ZW** .  
  
 Para obter mais informações, consulte [referência de linguagem do Visual C++](../../cppcx/visual-c-language-reference-c-cx.md).  
  
## <a name="requirements"></a>Requisitos  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)