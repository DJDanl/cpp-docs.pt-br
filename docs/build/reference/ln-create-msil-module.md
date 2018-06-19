---
title: -LN (Criar módulo MSIL) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /LN
dev_langs:
- C++
helpviewer_keywords:
- -LN compiler option [C++]
- /LN compiler option [C++]
ms.assetid: 4f38f4f4-3176-4caf-8200-5c7585dc1ed3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 918b3857c2e6f26a7f2e11614a00049e9b615ea8
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32375305"
---
# <a name="ln-create-msil-module"></a>/LN (criar módulo MSIL)
Especifica que um manifesto do assembly não deve ser inserido no arquivo de saída.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/LN  
```  
  
## <a name="remarks"></a>Comentários  
 Por padrão, **/LN** não está em vigor (um manifesto do assembly é inserido no arquivo de saída).  
  
 Quando **/LN** for usado, uma da [/clr (Common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md) opções também devem ser usadas.  
  
 Um programa gerenciado que não tem metadados do assembly no manifesto é chamado de um módulo. Se você compilar com [/c (compilar sem vinculação)](../../build/reference/c-compile-without-linking.md) e **/LN**, especifique [/NOASSEMBLY (criar um módulo MSIL)](../../build/reference/noassembly-create-a-msil-module.md) na fase de vinculador para criar o arquivo de saída.  
  
 Você talvez queira criar módulos se você deseja adotar uma abordagem baseado em componente para criação de assemblies.  Ou seja, você pode criar tipos e compilá-los em módulos.  Em seguida, você pode gerar um assembly de um ou mais módulos.  Para obter mais informações sobre como criar assemblies de módulos, consulte [. netmodule arquivos como entrada de vinculador](../../build/reference/netmodule-files-as-linker-input.md) ou [Al.exe (Assembly Linker)](/dotnet/framework/tools/al-exe-assembly-linker).  
  
 A extensão de arquivo padrão para um módulo é. netmodule.  
  
 Em [!INCLUDE[vcprvc](../../build/includes/vcprvc_md.md)] versões do Visual C++ 2005, um módulo foi criado com **/clr:noAssembly**.  
  
 O vinculador do Visual C++ aceita arquivos. netmodule como entrada e o arquivo de saída produzido pelo vinculador será um assembly ou. netmodule com nenhuma dependência de tempo de execução em qualquer uma da. netmodules que foram inseridos para o vinculador.  Para obter mais informações, consulte [. netmodule arquivos como entrada de vinculador](../../build/reference/netmodule-files-as-linker-input.md).  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
-   Especifique [/NOASSEMBLY (criar um módulo MSIL)](../../build/reference/noassembly-create-a-msil-module.md) na fase de vinculador para criar o arquivo de saída.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Essa opção de compilador não pode ser alterada de forma programática.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)