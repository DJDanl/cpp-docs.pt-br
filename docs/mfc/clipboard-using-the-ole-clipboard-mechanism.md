---
title: 'Área de Transferência: usando o mecanismo Área de Transferência OLE'
ms.date: 11/04/2016
helpviewer_keywords:
- applications [OLE], Clipboard
- OLE Clipboard
- Clipboard [MFC], OLE formats
- OLE Clipboard, formats
- formats [MFC], Clipboard for OLE
ms.assetid: 229cc610-5bb1-435e-bd20-2c8b9964d1af
ms.openlocfilehash: 3dadd2ae6774c684fe751e02fb3a80570accd30a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50661442"
---
# <a name="clipboard-using-the-ole-clipboard-mechanism"></a>Área de Transferência: usando o mecanismo Área de Transferência OLE

OLE usa os formatos padrão e alguns formatos específicos de OLE para a transferência de dados por meio da área de transferência.

Quando você recorta ou copia dados de um aplicativo, os dados são armazenados na área de transferência a ser usado posteriormente em operações de colagem. Esses dados estão em uma variedade de formatos. Quando um usuário escolhe colar dados da área de transferência, o aplicativo pode escolher qual desses formatos para usar. O aplicativo deve ser escrito para escolher o formato que fornece a maioria das informações, a menos que o usuário solicitar especificamente para um determinado formato, usando Colar especial. Antes de continuar, talvez você queira ler a [objetos de dados e fontes de dados (OLE)](../mfc/data-objects-and-data-sources-ole.md) tópicos. Eles descrevem os conceitos básicos de como funcionam as transferências de dados e como implementá-los em seus aplicativos.

Windows define um número de formatos padrão que pode ser usado para a transferência de dados por meio da área de transferência. Isso inclui metarquivos, texto, bitmaps e outras pessoas. OLE define um número de formatos de OLE específico. Para aplicativos que precisam de mais detalhes e fornecido por esses formatos padrão, é uma boa ideia registrar seus próprios formatos personalizados de área de transferência. Use a função de API do Win32 [RegisterClipboardFormat](/windows/desktop/api/winuser/nf-winuser-registerclipboardformata) para fazer isso.

Por exemplo, o Microsoft Excel registra um formato personalizado para planilhas. Esse formato transporta informações muito mais que, por exemplo, um bitmap faz. Quando esses dados são colados em um aplicativo que dá suporte ao formato de planilha, todas as fórmulas e os valores da planilha são mantidos e podem ser atualizados, se necessário. O Microsoft Excel também coloca os dados na área de transferência em formatos para que ele pode ser colado como um item OLE. Qualquer contêiner de documento OLE pode colar essas informações como um item inserido. Este item inserido pode ser alterado usando o Microsoft Excel. A área de transferência também contém um bitmap simples da imagem do intervalo selecionado na planilha. Isso também pode ser colado em contêineres de documento OLE ou editores de bitmap, como tinta. No caso de um bitmap, no entanto, não há nenhuma maneira de manipular os dados como uma planilha.

Para recuperar a quantidade máxima de informações da área de transferência, os aplicativos devem verificar para esses formatos personalizados antes de colar os dados da área de transferência.

Por exemplo, para habilitar o comando Recortar, você pode escrever um manipulador de algo semelhante ao seguinte:

[!code-cpp[NVC_MFCListView#3](../atl/reference/codesnippet/cpp/clipboard-using-the-ole-clipboard-mechanism_1.cpp)]

## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Copiando e colando dados](../mfc/clipboard-copying-and-pasting-data.md)

- [Adicionando outros formatos](../mfc/clipboard-adding-other-formats.md)

- [Usando a área de transferência do Windows](../mfc/clipboard-using-the-windows-clipboard.md)

- [OLE](../mfc/ole-background.md)

- [Transferência de dados uniformes e fontes de dados e objetos de dados OLE](../mfc/data-objects-and-data-sources-ole.md)

## <a name="see-also"></a>Consulte também

[Área de transferência](../mfc/clipboard.md)

