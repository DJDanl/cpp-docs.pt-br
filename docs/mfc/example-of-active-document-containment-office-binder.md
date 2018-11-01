---
title: 'Exemplo de confinamento do documento ativo: Office Binder'
ms.date: 11/04/2016
helpviewer_keywords:
- active documents [MFC], containers
- examples [MFC], active document containment
- containers [MFC], active document
- active document containers [MFC], examples
- Office Binder [MFC]
- MFC COM, active document containment
ms.assetid: 70dd8568-e8bc-44ac-bf5e-678767efe8e3
ms.openlocfilehash: 032b2cb39d75c108239d882039f7c797a357a6bc
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50616644"
---
# <a name="example-of-active-document-containment-office-binder"></a>Exemplo de confinamento do documento ativo: Office Binder

O Microsoft Office Binder é um exemplo de um contêiner de documento ativo. Um associador de Office inclui dois painéis principais, como contêineres normalmente fazem. O painel esquerdo contém ícones que correspondem aos documentos ativos do fichário. Cada documento é chamado de um *seção* dentro do associador. Por exemplo, um fichário pode conter arquivos do PowerPoint, documentos do Word, planilhas do Excel e assim por diante.

Clicar em um ícone no painel esquerdo ativa o documento ativo correspondente. O painel direito do associador, em seguida, exibe o conteúdo do documento ativo atualmente selecionado.

Se você abrir e ativa um documento do Word em um fichário, Word barra de menus e barras de ferramentas aparecem na parte superior do quadro de exibição, e você pode editar o conteúdo do documento usando qualquer comando do Word ou a ferramenta. No entanto, a barra de menu é uma combinação de barras de menus do associador tanto do Word. Porque o associador e o Word têm **ajudar** menus, o conteúdo dos respectivos menus são mesclados. Os contêineres de documento ativo, como Office Binder automaticamente fornecem **ajudar** menu mesclando; para obter mais informações, consulte [ajuda a mesclagem de Menu](../mfc/help-menu-merging.md).

Quando você seleciona um documento ativo de outro tipo de aplicativo, alterações na interface do fichário para atender a esse tipo de aplicativo do documento ativo. Por exemplo, se um fichário contiver uma planilha do Excel, você observará que os menus do fichário alterar quando você seleciona a seção de planilha do Excel.

É claro, há outros possíveis tipos de contêineres ao lado de associadores. Explorador de arquivos usa a interface dupla painel típica em que o painel esquerdo usa um controle de árvore para exibir uma lista hierárquica de diretórios em uma unidade ou a rede, enquanto o painel direito exibe os arquivos contidos no diretório selecionado no momento. Um tipo de navegador da Internet do contêiner (como o Microsoft Internet Explorer), em vez de usar uma interface dupla painel, geralmente tem um único quadro e fornece o uso de hiperlinks de navegação.

## <a name="see-also"></a>Consulte também

[Contenção de documentos ativos](../mfc/active-document-containment.md)

