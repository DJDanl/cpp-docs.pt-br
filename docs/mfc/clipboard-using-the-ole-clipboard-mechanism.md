---
title: "Área de transferência: Usando o mecanismo da área de transferência OLE | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- applications [OLE], Clipboard
- OLE Clipboard
- Clipboard [MFC], OLE formats
- OLE Clipboard, formats
- formats [MFC], Clipboard for OLE
ms.assetid: 229cc610-5bb1-435e-bd20-2c8b9964d1af
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 4996c6559ad20141fb84ed37e87fd1551e89a77b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="clipboard-using-the-ole-clipboard-mechanism"></a>Área de Transferência: usando o mecanismo Área de Transferência OLE
OLE usa os formatos padrão e alguns formatos OLE específico para a transferência de dados por meio da área de transferência.  
  
 Quando você recorta ou copia dados de um aplicativo, os dados são armazenados na área de transferência a ser usado posteriormente em operações de colagem. Esses dados estão em uma variedade de formatos. Quando um usuário opta por colar os dados da área de transferência, o aplicativo pode escolher qual esses formatos para uso. O aplicativo deve ser escrito para escolher o formato que fornece a maioria das informações, a menos que o usuário solicitar especificamente para um determinado formato, Colar especial. Antes de continuar, talvez você queira ler a [objetos de dados e fontes de dados (OLE)](../mfc/data-objects-and-data-sources-ole.md) tópicos. Eles descrevem os conceitos básicos de como funcionam as transferências de dados e como implementá-los em seus aplicativos.  
  
 Windows define um número de formatos padrão que pode ser usado para a transferência de dados por meio da área de transferência. Isso inclui metarquivos, texto, bitmaps e outros. OLE define um número de formatos de OLE específico. Para aplicativos que precisam de mais detalhes e fornecido por esses formatos padrão, é uma boa ideia para registrar seus próprios formatos personalizados de área de transferência. Use a função de API do Win32 [RegisterClipboardFormat](http://msdn.microsoft.com/library/windows/desktop/ms649049) para fazer isso.  
  
 Por exemplo, o Microsoft Excel registra um formato personalizado de planilhas. Esse formato executa muito mais informações que, por exemplo, faz de um bitmap. Quando essa data será colado em um aplicativo que ofereça suporte ao formato de planilha, todas as fórmulas e os valores da planilha são mantidos e podem ser atualizados, se necessário. O Microsoft Excel também coloca os dados na área de transferência em formatos para que ele pode ser colado como um item OLE. Nenhum contêiner de documento OLE pode colar essas informações como um item inserido. Este item inserido pode ser alterado usando o Microsoft Excel. A área de transferência também contém um bitmap simples da imagem do intervalo selecionado na planilha. Isso também pode ser colado em contêineres de documento OLE ou editores de bitmap, como o Paint. No caso de um bitmap, no entanto, não é possível manipular os dados como uma planilha.  
  
 Para recuperar o número máximo de informações da área de transferência, aplicativos devem verificar esses formatos personalizados antes de colar os dados da área de transferência.  
  
 Por exemplo, para habilitar o comando Cortar, você pode escrever um manipulador de algo semelhante ao seguinte:  
  
 [!code-cpp[NVC_MFCListView#3](../atl/reference/codesnippet/cpp/clipboard-using-the-ole-clipboard-mechanism_1.cpp)]  
  
## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Copiando e colando dados](../mfc/clipboard-copying-and-pasting-data.md)  
  
-   [Adicionando outros formatos](../mfc/clipboard-adding-other-formats.md)  
  
-   [Usando a área de transferência do Windows](../mfc/clipboard-using-the-windows-clipboard.md)  
  
-   [OLE](../mfc/ole-background.md)  
  
-   [Transferência de dados uniformes e fontes de dados e objetos de dados OLE](../mfc/data-objects-and-data-sources-ole.md)  
  
## <a name="see-also"></a>Consulte também  
 [Área de transferência](../mfc/clipboard.md)

