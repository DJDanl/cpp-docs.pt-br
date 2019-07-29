---
title: /MANIFESTINPUT (especificar entrada de manifesto)
ms.date: 07/24/2019
ms.assetid: a0b0c21e-1f9b-4d8c-bb3f-178f57fa7f1b
ms.openlocfilehash: 7b7bd54f98003d9158276fcf75fd61ffb5348585
ms.sourcegitcommit: 720b74dddb1cdf4e570d55103158304ee1df81f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/29/2019
ms.locfileid: "68606468"
---
# <a name="manifestinput-specify-manifest-input"></a>/MANIFESTINPUT (especificar entrada de manifesto)

Especifica um arquivo de entrada de manifesto a ser incluído no manifesto inserido na imagem.

## <a name="syntax"></a>Sintaxe

```
/MANIFESTINPUT:filename
```

### <a name="parameters"></a>Parâmetros

*filename*<br/>
O arquivo de manifesto a ser incluído no manifesto inserido.

## <a name="remarks"></a>Comentários

A opção **/MANIFESTINPUT** especifica o caminho de um arquivo de entrada a ser usado para criar o manifesto inserido em uma imagem executável. Se você tiver vários arquivos de entrada de manifesto, use a opção várias vezes — uma vez para cada arquivo de entrada. Os arquivos de entrada do manifesto são mesclados para criar o manifesto inserido. Essa opção requer a opção **/manifest: embed** .

Esta opção não pode ser definida diretamente no Visual Studio. Em vez disso, use a propriedade **adicional de arquivos de manifesto** do projeto para especificar arquivos de manifesto adicionais a serem incluídos. Para obter mais informações, consulte [páginas de propriedades da ferramenta de manifesto](manifest-tool-property-pages.md).

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
