---
title: -vd (desabilitar deslocamentos de construção) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /vd
dev_langs:
- C++
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4e983da4521db077235c2b879e0d1277b9505e94
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42605862"
---
# <a name="vd-disable-construction-displacements"></a>/vd (desabilitar deslocamentos de construção)
## <a name="syntax"></a>Sintaxe  
  
```  
/vdn  
```  
  
## <a name="arguments"></a>Arguments  
 `0`  
 Suprime o membro construtor/destruidor vtordisp. Escolha esta opção somente se você tiver certeza de que todos os construtores de classe e os destruidores chamam virtuais funciona praticamente.  
  
 `1`  
 Permite a criação de membros de deslocamento do construtor/destruidor vtordisp ocultos. Essa opção é o padrão.  
  
 `2`  
 Permite que você use [operador dynamic_cast](../../cpp/dynamic-cast-operator.md) em um objeto que está sendo construído. Por exemplo, um dynamic_cast de uma classe base virtual a uma classe derivada.  
  
 **/ vd2** adiciona um campo de vtordisp quando você tem uma base virtual com funções virtuais. **/ vd1** deve ser suficiente. O mais comum de casos onde **/vd2** é necessário é quando a função virtual somente em sua base virtual é um destruidor.  
  
## <a name="remarks"></a>Comentários  
 Essas opções se aplicam somente ao código de C++ que usa bases virtuais.  
  
 Visual C++ implementa o suporte de deslocamento de construção de C++ em situações em que a herança virtual é usada. Deslocamentos de construção resolve o problema criado quando uma função virtual, declarado em uma base virtual e substituído em uma classe derivada, é chamado durante a construção de uma classe derivada mais de um construtor.  
  
 O problema é que a função virtual pode ser passada incorreta `this` ponteiro como resultado de discrepâncias entre os deslocamentos em virtual bases de uma classe e os deslocamentos de suas classes derivadas. A solução fornece um ajuste de deslocamento de construção único, chamado de um campo de vtordisp, para cada base virtual de uma classe.  
  
 Por padrão, os campos vtordisp são introduzidos sempre que o código define os destruidores e construtores definidos pelo usuário e também substitui as funções virtuais de bases virtuais.  
  
 Essas opções afetam os arquivos de origem inteira. Use [vtordisp](../../preprocessor/vtordisp.md) suprimir e, em seguida, reabilitar os campos vtordisp classe por classe.  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Clique o **C/C++** pasta.  
  
3.  Clique o **linha de comando** página de propriedades.  
  
4.  Digite a opção de compilador na **opções adicionais** caixa.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)