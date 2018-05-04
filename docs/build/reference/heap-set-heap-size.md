---
title: -HEAP (Definir tamanho do Heap) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCLinkerTool.HeapCommitSize
- /heap
- VC.Project.VCLinkerTool.HeapReserveSize
dev_langs:
- C++
helpviewer_keywords:
- -HEAP linker option
- heap allocation, setting heap size
- /HEAP linker option
- HEAP linker option
ms.assetid: a3f71927-7f1d-492c-9fdb-dfccb1a043da
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7b968b3c8e9063eea897c70d4ae2a62a9a232d6b
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="heap-set-heap-size"></a>/HEAP (definir tamanho do heap)
```  
/HEAP:reserve[,commit]  
```  
  
## <a name="remarks"></a>Comentários  
 A opção /HEAP define o tamanho do heap em bytes. Essa opção é somente para uso ao criar um arquivo .exe.  
  
 O *reservar* argumento especifica a alocação de heap total na memória virtual. O tamanho do heap padrão é 1 MB. O vinculador Arredonda o valor especificado para os mais próximos 4 bytes.  
  
 Opcional `commit` argumento especifica a quantidade de memória física para alocar a cada vez. Memória virtual confirmada faz com que o espaço a ser reservado no arquivo de paginação. Um maior `commit` valor economiza tempo quando o aplicativo precisa de mais espaço de heap, mas aumenta os requisitos de memória e, possivelmente, o tempo de inicialização.  
  
 Especifique o *reservar* e `commit` valores em decimal ou notação de linguagem C.  
  
 Essa funcionalidade também está disponível por meio de um arquivo de definição de módulo com [HEAPSIZE](../../build/reference/heapsize.md).  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).  
  
2.  Clique o **vinculador** pasta.  
  
3.  Clique o **sistema** página de propriedades.  
  
4.  Modificar o **tamanho de confirmação de Heap** propriedade.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.HeapReserveSize%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.HeapCommitSize%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)