---
title: -await (Habilitar suporte de corrotina) | Microsoft Docs
ms.custom: ''
ms.date: 08/15/2017
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /await
- -await
dev_langs:
- C++
helpviewer_keywords:
- /await enable coroutine support [C++]
- -await enable coroutine support [C++]
- await enable coroutine support [C++]
ms.assetid: 302c8e69-09b6-4c58-bcdd-0a6a8713a8df
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 78a62195ca28be49ed8c00dacacce003281699f9
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32371025"
---
# <a name="await-enable-coroutine-support"></a>/ await (Habilitar suporte de corrotina)  
  
Use o **/ await** opção de compilador para habilitar o suporte para corrotinas compilador.  
  
## <a name="syntax"></a>Sintaxe  
  
> / await  
  
## <a name="remarks"></a>Comentários  
  
O **/ await** opção de compilador habilita o suporte de compilador para co-rotinas C++ e as palavras-chave **co_await**, **co_yield**, e **co_return**. Essa opção fica desativada por padrão. Para obter informações sobre o suporte para corrotinas no Visual Studio, consulte o [Blog da equipe do Visual Studio](https://blogs.msdn.microsoft.com/vcblog/category/coroutine/). Para obter mais informações sobre a proposta de co-rotinas padrão, consulte [N4628 rascunho de trabalho, especificação técnica para extensões de C++ para co-rotinas](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/n4628.pdf).  

O **/ await** opção está disponível a partir no Visual Studio 2015.  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1. Abra seu projeto **páginas de propriedade** caixa de diálogo.   
  
2. Em **propriedades de configuração**, expanda o **C/C++** pasta e escolha o **linha de comando** página de propriedades.  
  
3. Insira o **/ await** opção de compilador no **opções adicionais** caixa. Escolha **Okey** ou **aplicar** para salvar suas alterações.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## <a name="see-also"></a>Consulte também  
  
[Opções do compilador](../../build/reference/compiler-options.md)   
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)