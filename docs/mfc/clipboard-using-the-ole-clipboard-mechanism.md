---
title: 'Área de transferência: Usando o mecanismo de área de transferência OLE'
ms.date: 11/04/2016
helpviewer_keywords:
- applications [OLE], Clipboard
- OLE Clipboard
- Clipboard [MFC], OLE formats
- OLE Clipboard, formats
- formats [MFC], Clipboard for OLE
ms.assetid: 229cc610-5bb1-435e-bd20-2c8b9964d1af
ms.openlocfilehash: 0f2c10f4a88b723d1ab9f4bb0ca903987359c9fd
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69508913"
---
# <a name="clipboard-using-the-ole-clipboard-mechanism"></a>Área de transferência: Usando o mecanismo de área de transferência OLE

O OLE usa formatos padrão e alguns formatos específicos de OLE para transferir dados por meio da área de transferência.

Quando você recorta ou copia dados de um aplicativo, os dados são armazenados na área de transferência para serem usados posteriormente em operações de colagem. Esses dados estão em uma variedade de formatos. Quando um usuário opta por colar dados da área de transferência, o aplicativo pode escolher quais desses formatos usar. O aplicativo deve ser escrito para escolher o formato que fornece a maioria das informações, a menos que o usuário solicite especificamente um determinado formato, usando colar especial. Antes de continuar, talvez você queira ler os tópicos [objetos de dados e fontes de dados (OLE)](../mfc/data-objects-and-data-sources-ole.md) . Eles descrevem os conceitos básicos de como as transferências de dados funcionam e como implementá-las em seus aplicativos.

O Windows define vários formatos padrão que podem ser usados para transferir dados por meio da área de transferência. Isso inclui metaarquivos, texto, bitmaps e outros. O OLE também define um número de formatos específicos de OLE. Para aplicativos que precisam de mais detalhes do que os fornecidos por esses formatos padrão, é uma boa ideia registrar seus próprios formatos de área de transferência personalizados. Use a função de API do Win32 [RegisterClipboardFormat](/windows/win32/api/winuser/nf-winuser-registerclipboardformatw) para fazer isso.

Por exemplo, o Microsoft Excel registra um formato personalizado para planilhas. Esse formato contém muito mais informações do que, por exemplo, um bitmap faz. Quando esses dados são colados em um aplicativo que dá suporte ao formato de planilha, todas as fórmulas e valores da planilha são mantidos e podem ser atualizados, se necessário. O Microsoft Excel também coloca dados na área de transferência em formatos para que possam ser colados como um item OLE. Qualquer contêiner de documento OLE pode colar essas informações como um item incorporado. Este item inserido pode ser alterado usando o Microsoft Excel. A área de transferência também contém um bitmap simples da imagem do intervalo selecionado na planilha. Isso também pode ser colado em contêineres de documento OLE ou em editores de bitmap, como o Paint. No entanto, no caso de um bitmap, não há como manipular os dados como uma planilha.

Para recuperar a quantidade máxima de informações da área de transferência, os aplicativos devem verificar esses formatos personalizados antes de colar os dados da área de transferência.

Por exemplo, para habilitar o comando Recortar, você pode escrever um manipulador semelhante ao seguinte:

[!code-cpp[NVC_MFCListView#3](../atl/reference/codesnippet/cpp/clipboard-using-the-ole-clipboard-mechanism_1.cpp)]

## <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Copiando e colando dados](../mfc/clipboard-copying-and-pasting-data.md)

- [Adicionando outros formatos](../mfc/clipboard-adding-other-formats.md)

- [Usando a área de transferência do Windows](../mfc/clipboard-using-the-windows-clipboard.md)

- [OLEDB](../mfc/ole-background.md)

- [Objetos de dados OLE e fontes de dados e transferência de dados uniforme](../mfc/data-objects-and-data-sources-ole.md)

## <a name="see-also"></a>Consulte também

[Área de transferência](../mfc/clipboard.md)
