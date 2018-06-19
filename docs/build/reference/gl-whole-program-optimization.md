---
title: -GL (otimização de programa parcial) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /gl
- VC.Project.VCCLWCECompilerTool.WholeProgramOptimization
dev_langs:
- C++
helpviewer_keywords:
- /GL compiler option [C++]
- whole program optimizations and C++ compiler
- -GL compiler option [C++]
- GL compiler option [C++]
ms.assetid: 09d51e2d-9728-4bd0-b5dc-3b8284aca1d1
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ce972b6e7254ad7454f8e8799283588f0fdd5270
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32376267"
---
# <a name="gl-whole-program-optimization"></a>/GL (otimização de todo o programa)
Habilita a otimização de todo o programa.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/GL[-]  
```  
  
## <a name="remarks"></a>Comentários  
 Otimização de programa parcial permite que o compilador realizar otimizações com informações em todos os módulos no programa. Sem otimização de programa parcial, otimizações são executadas em um acordo de módulo (compiland).  
  
 Otimização de todo o programa está desativado por padrão e deve ser explicitamente habilitada. No entanto, também é possível desabilitá-la com explicitamente **/GL-**.  
  
 Informações sobre todos os módulos, o compilador pode:  
  
-   Otimize o uso de registros em limites de função.  
  
-   Fazer um trabalho melhor de modificações de dados globais, permitindo uma redução no número de carregamentos e repositórios de controle.  
  
-   Fazer um trabalho melhor de cancelar o conjunto de possíveis de itens modificados por um ponteiro, reduzindo os números de carregamentos e repositórios de controle.  
  
-   Uma função em um módulo, mesmo quando a função é definida em outro módulo do embutido.  
  
 arquivos. obj produzido com **/GL** não estarão disponíveis para esses utilitários de vinculador como [EDITBIN](../../build/reference/editbin-reference.md) e [DUMPBIN](../../build/reference/dumpbin-reference.md).  
  
 Se você compilar seu programa com **/GL** e [/c](../../build/reference/c-compile-without-linking.md), você deve usar a opção de vinculador /LTCG para criar o arquivo de saída.  
  
 [/Zi](../../build/reference/z7-zi-zi-debug-information-format.md) não pode ser usado com **/GL**  
  
 O formato dos arquivos produzido com **/GL** na versão atual não possa ser lido por versões subsequentes do Visual C++. Você não deve fornecer um arquivo composto por arquivos. obj produzidas com **/GL** , a menos que você está disposto a enviar cópias do arquivo. lib para todas as versões do Visual C++ você espera que os usuários usem, agora e no futuro.  
  
 arquivos. obj produzido com **/GL** e arquivos de cabeçalho pré-compilado não devem ser usados para criar um arquivo. lib, a menos que o arquivo. lib será vinculado na mesma máquina que produziu o **/GL** arquivo. obj. Informações do arquivo de cabeçalho pré-compilado do arquivo. obj serão necessária em tempo de link.  
  
 Para obter mais informações sobre as otimizações disponíveis com e as limitações de otimização de todo o programa, consulte [/LTCG](../../build/reference/ltcg-link-time-code-generation.md).  **/GL** também o torna disponível de Otimização Guiada por perfil; consulte /LTCG.  Ao compilar para guiada por perfil otimizações e se você quiser ordenação de seu otimizações guiadas por perfil de função, você deve compilar com [/Gy](../../build/reference/gy-enable-function-level-linking.md) ou uma opção de compilador que implica /Gy.  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Consulte [/LTCG (geração de código Link-time)](../../build/reference/ltcg-link-time-code-generation.md) para obter informações sobre como especificar **/GL** no ambiente de desenvolvimento.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
1.  Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.WholeProgramOptimization%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)