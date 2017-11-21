---
title: "-vd (desabilitar deslocamentos de construção) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: /vd
dev_langs: C++
helpviewer_keywords:
- -vd0 compiler option [C++]
- vd1 compiler option [C++]
- /vdn (Disable Construction Displacement) compiler option
- constructor displacements
- vtordisp fields
- /vd0 compiler option [C++]
- -vd1 compiler option [C++]
- /vd1 compiler option [C++]
- displacements compiler option
- vd0 compiler option [C++]
- Disable Construction Displacements compiler option
ms.assetid: 93258964-14d7-4b1c-9cbc-d6f4d74eab69
caps.latest.revision: "17"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 0c06c67142e3e0af4582292304ff2eee8445e014
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="vd-disable-construction-displacements"></a>/vd (desabilitar deslocamentos de construção)
## <a name="syntax"></a>Sintaxe  
  
```  
/vdn  
```  
  
## <a name="arguments"></a>Arguments  
 `0`  
 Suprime o membro de deslocamento vtordisp construtor/destruidor. Escolha esta opção somente se você tiver certeza de que todos os construtores de classe e destruidores chamada virtuais funciona praticamente.  
  
 `1`  
 Permite a criação de membros de deslocamento de construtor/destruidor vtordisp oculto. Essa opção é o padrão.  
  
 `2`  
 Permite que você use [operador dynamic_cast](../../cpp/dynamic-cast-operator.md) em um objeto que está sendo construído. Por exemplo, um dynamic_cast de uma classe base virtual a uma classe derivada.  
  
 **/vd2** adiciona um campo vtordisp quando você tem uma base virtual com funções virtuais. **/vd1** devem ser suficientes. O mais comum caso onde **/vd2** é necessário quando a função virtual somente em sua base virtual é um destruidor.  
  
## <a name="remarks"></a>Comentários  
 Estas opções se aplicam somente ao código do C++ que usa bases virtual.  
  
 [!INCLUDE[vcprvc](../../build/includes/vcprvc_md.md)]implementa o suporte de deslocamento de construção de C++ em situações em que a herança virtual é usada. Deslocamentos de construção resolve o problema criado quando uma função virtual, declarado em uma base virtual e substituído em uma classe derivada, é chamado de um construtor durante a construção de uma classe derivada adicional.  
  
 O problema é que a função virtual pode ser passada incorreta `this` ponteiro como resultado de discrepâncias entre os deslocamentos de virtual bases de uma classe e os deslocamentos de suas classes derivadas. A solução fornece um ajuste de deslocamento de construção único, chamado de campo de vtordisp, para cada base virtual de uma classe.  
  
 Por padrão, os campos vtordisp são introduzidos sempre que o código define destruidores e construtores definidos pelo usuário e também substitui funções virtuais de bases virtuais.  
  
 Essas opções afetam os arquivos de origem inteiro. Use [vtordisp](../../preprocessor/vtordisp.md) suprimir e, em seguida, reabilitar campos vtordisp em uma base por classe.  
  
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