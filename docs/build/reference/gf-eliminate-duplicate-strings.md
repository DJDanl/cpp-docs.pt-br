---
title: -GF (eliminar cadeias de caracteres duplicadas) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCCLCompilerTool.StringPooling
- VC.Project.VCCLWCECompilerTool.StringPooling
- /gf
dev_langs: C++
helpviewer_keywords:
- duplicate strings
- Eliminate Duplicate Strings compiler option [C++]
- pooling strings compiler option [C++]
- -GF compiler option [C++]
- /GF compiler option [C++]
- GF compiler option [C++]
- strings [C++], pooling
ms.assetid: bb7b5d1c-8e1f-453b-9298-8fcebf37d16c
caps.latest.revision: "17"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: d69e892fb9487b66da4dfa2a801bab302e962af7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="gf-eliminate-duplicate-strings"></a>/GF (eliminar cadeias de caracteres duplicadas)
Permite que o compilador criar uma cópia única de cadeias de caracteres idênticas na imagem do programa e na memória durante a execução. Essa é uma otimização chamada *pooling de cadeia de caracteres* que você pode criar programas menores.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/GF  
```  
  
## <a name="remarks"></a>Comentários  
 Se você usar **/GF**, o sistema operacional não substitua a parte da cadeia de caracteres de memória e pode ler as cadeias de caracteres de volta do arquivo de imagem.  
  
 **/GF** pools de cadeias de caracteres como somente leitura. Se você tentar modificar cadeias de caracteres em **/GF**, ocorrerá um erro de aplicativo.  
  
 Pool de cadeia de caracteres permite que o objetivo como vários ponteiros para buffers de várias for vários ponteiros para um único buffer. No código a seguir, `s` e `t` são inicializados com a mesma cadeia de caracteres. Pool de cadeia de caracteres faz com que elas apontam para a mesma memória:  
  
```  
char *s = "This is a character buffer";  
char *t = "This is a character buffer";  
```  
  
> [!NOTE]
>  O [/ZI](../../build/reference/z7-zi-zi-debug-information-format.md) opcional usada para editar e continuar, define automaticamente o **/GF** opção.  
  
> [!NOTE]
>  O **/GF** opção de compilador cria uma seção endereçável para cada cadeia de caracteres exclusiva. E, por padrão, um arquivo de objeto pode conter até 65.536 seções endereçável. Se seu programa contiver mais de 65.536 cadeias de caracteres, use o [/bigobj](../../build/reference/bigobj-increase-number-of-sections-in-dot-obj-file.md) opção de compilador para criar mais seções.  
  
 **/GF** está em vigor quando [/O1](../../build/reference/o1-o2-minimize-size-maximize-speed.md) ou **/O2** é usado.  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Clique o **C/C++** pasta.  
  
3.  Clique o **geração de código** página de propriedades.  
  
4.  Modificar o **ativar pool de cadeia de caracteres** propriedade.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.StringPooling%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)