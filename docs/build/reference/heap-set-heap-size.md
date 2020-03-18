---
title: /HEAP (definir tamanho do heap)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCLinkerTool.HeapCommitSize
- VC.Project.VCLinkerTool.HeapReserveSize
helpviewer_keywords:
- -HEAP linker option
- heap allocation, setting heap size
- /HEAP linker option
- HEAP linker option
ms.assetid: a3f71927-7f1d-492c-9fdb-dfccb1a043da
ms.openlocfilehash: f155ad56ec1a90479b402e38e7ec7f3e3d80e470
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79439528"
---
# <a name="heap-set-heap-size"></a>/HEAP (definir tamanho do heap)

```
/HEAP:reserve[,commit]
```

## <a name="remarks"></a>Comentários

A opção/HEAP define o tamanho do heap em bytes. Essa opção só é usada para a criação de um arquivo. exe.

O argumento *Reserve* especifica a alocação de heap total na memória virtual. O tamanho de heap padrão é 1 MB. O vinculador arredonda o valor especificado para os 4 bytes mais próximos.

O argumento opcional `commit` especifica a quantidade de memória física a ser alocada de cada vez. A memória virtual confirmada faz com que o espaço seja reservado no arquivo de paginação. Um valor mais alto `commit` economiza tempo quando o aplicativo precisa de mais espaço de heap, mas aumenta os requisitos de memória e, possivelmente, o tempo de inicialização.

Especifique os valores de *reserva* e `commit` em notação decimal ou C-Language.

Essa funcionalidade também está disponível por meio de um arquivo de definição de módulo com [heapsize](heapsize.md).

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Clique na pasta **Vinculador**.

1. Clique na página de propriedades do **sistema** .

1. Modifique a propriedade **tamanho de confirmação de heap** .

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.HeapReserveSize%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.HeapCommitSize%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
