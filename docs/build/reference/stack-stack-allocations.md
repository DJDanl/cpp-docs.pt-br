---
title: -PILHA (alocações da pilha) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCLinkerTool.StackReserveSize
- VC.Project.VCLinkerTool.StackCommitSize
- /stack
dev_langs:
- C++
helpviewer_keywords:
- STACK linker option
- -STACK linker option
- memory allocation, stack
- /STACK linker option
- stack, setting size
ms.assetid: 73283660-e4bd-47cc-b5ca-04c5d739034c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c8ee3fac90bcbb972278d9b3e2cf7cebd62fedf4
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="stack-stack-allocations"></a>/STACK (alocações da pilha)
```  
/STACK:reserve[,commit]  
```  
  
## <a name="remarks"></a>Comentários  
 A opção /STACK define o tamanho da pilha em bytes. Use esta opção somente quando você cria um arquivo .exe.  
  
 O `reserve` valor Especifica a alocação da pilha total na memória virtual. Para ARM, x86 e [!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)] máquinas, o tamanho da pilha padrão é 1 MB.  
  
 `commit` está sujeita a interpretação pelo sistema operacional. No Windows WindowsRT Especifica a quantidade de memória física para alocar a cada vez. Memória virtual confirmada faz com que o espaço a ser reservado no arquivo de paginação. Um maior `commit` valor economiza tempo quando o aplicativo precisa de mais espaço de pilha, mas aumenta os requisitos de memória e, possivelmente, o tempo de inicialização. Para ARM, x86 e [!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)] máquinas, o valor de confirmação padrão é 4 KB.  
  
 Especifique o `reserve` e `commit` valores em decimal ou notação de linguagem C.  
  
 Outra maneira de definir o tamanho da pilha é com o [STACKSIZE](../../build/reference/stacksize.md) instrução em um arquivo de definição de módulo (. def). **STACKSIZE** substitui as alocações de pilha (/ pilha) opção se ambos estiverem especificados. Você pode alterar o tamanho da pilha depois que o arquivo .exe é criado usando o [EDITBIN](../../build/reference/editbin-reference.md) ferramenta.  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).  
  
2.  Selecione o **vinculador** pasta.  
  
3.  Selecione o **sistema** página de propriedades.  
  
4.  Modificar uma das seguintes propriedades:  
  
    -   **Tamanho de confirmação da pilha**  
  
    -   **Tamanho de reserva da pilha**  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
1.  Consulte as propriedades <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.StackCommitSize%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.StackReserveSize%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)