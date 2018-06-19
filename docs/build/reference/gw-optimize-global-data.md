---
title: -Gw (otimizar dados globais) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /Gw
dev_langs:
- C++
helpviewer_keywords:
- /Gw compiler option [C++]
- -Gw compiler option [C++]
ms.assetid: 6f90f4e9-5eb8-4c47-886e-631278a5a4a9
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 173b9499477ee02cbb1f052d3d85445a9ffb7732
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32376433"
---
# <a name="gw-optimize-global-data"></a>/Gw (Otimizar dados globais)
Dados globais do pacote nas seções COMDAT para otimização.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/Gw[-]  
```  
  
## <a name="remarks"></a>Comentários  
 O **/Gw** opção faz com que o compilador para dados globais do pacote nas seções COMDAT individuais. Por padrão, **/Gw** está desativado e deve ser explicitamente habilitado. Para desabilitá-la explicitamente, use **/Gw-**. Quando ambos **/Gw** e [/GL](../../build/reference/gl-whole-program-optimization.md) estiver habilitado, o vinculador usa otimização de programa inteiro para comparar seções COMDAT em vários arquivos de objeto para excluir dados globais não referenciados ou de mesclagem dados idênticos de global somente leitura. Isso pode reduzir significativamente o tamanho do binário resultante executável.  
  
 Quando você compila e vincular separadamente, você pode usar o [/OPT: REF](../../build/reference/opt-optimizations.md) opção de vinculador para excluir do executável os dados globais não referenciados nos arquivos de objeto compilados com o **/Gw** opção.  
  
 Você também pode usar o [/OPT: ICF](../../build/reference/opt-optimizations.md) e [/LTCG](../../build/reference/ltcg-link-time-code-generation.md) opções do vinculador para mesclar o executável qualquer somente leitura global dados idênticos em vários arquivos de objeto compilados com o **/Gw** opção.  
  
 Para obter mais informações, consulte [apresentando /Gw opção de compilador](http://blogs.msdn.com/b/vcblog/archive/2013/09/11/introducing-gw-compiler-switch.aspx) no Blog da equipe do Visual C++.  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione o **C/C++** pasta.  
  
3.  Selecione o **linha de comando** página de propriedades.  
  
4.  Modificar o **opções adicionais** propriedade incluir **/Gw** e, em seguida, escolha **Okey**.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)