---
title: /MANIFESTINPUT (especificar entrada de manifesto)
ms.date: 11/04/2016
ms.assetid: a0b0c21e-1f9b-4d8c-bb3f-178f57fa7f1b
ms.openlocfilehash: bf192664a7a2402b06621167d91dff67ce0741a9
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62321352"
---
# <a name="manifestinput-specify-manifest-input"></a>/MANIFESTINPUT (especificar entrada de manifesto)

Especifica um arquivo de entrada de manifesto para incluir no manifesto inserido na imagem.

## <a name="syntax"></a>Sintaxe

```
/MANIFESTINPUT:filename
```

### <a name="parameters"></a>Parâmetros

*filename*<br/>
O arquivo de manifesto para incluir no manifesto inserido.

## <a name="remarks"></a>Comentários

O **/MANIFESTINPUT** opção especifica o caminho de um arquivo de entrada para usar para criar o manifesto inserido em uma imagem executável. Se você tiver o manifesto de vários arquivos de entrada, use a opção várias vezes — uma vez para cada arquivo de entrada. Os arquivos de entrada de manifesto são mesclados para criar o manifesto inserido. Essa opção requer o **/MANIFEST: inserir** opção.

Essa opção não pode ser definida diretamente no Visual Studio. Em vez disso, use o **arquivos de manifesto adicionais** propriedade do projeto para especificar os arquivos de manifesto adicionais para incluir. Para obter mais informações, consulte [entrada e saída, ferramenta de manifesto, propriedades de configuração \<Projectname > caixa de diálogo páginas de propriedades](input-and-output-manifest-tool.md).

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
