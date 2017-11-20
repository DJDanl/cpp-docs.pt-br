---
title: "-ZW (compilação de tempo de execução do Windows) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCCLCompilerTool.CompileAsWinRT
- /zw
dev_langs: C++
helpviewer_keywords:
- /ZW
- -ZW compiler option
- /ZW compiler option
- -ZW
- Windows Runtime compiler option
ms.assetid: 0fe362b0-9526-498b-96e0-00d7a965a248
caps.latest.revision: "13"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 4af8070518cbb35d2f005fd255675ab4fb334b38
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="zw-windows-runtime-compilation"></a>/ZW (Compilação de Windows Runtime )
Compila o código-fonte para permitir o uso de [!INCLUDE[cppwrt](../../build/reference/includes/cppwrt_md.md)] ([!INCLUDE[cppwrt_short](../../build/reference/includes/cppwrt_short_md.md)]) na criação de aplicativos da [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)].  
  
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