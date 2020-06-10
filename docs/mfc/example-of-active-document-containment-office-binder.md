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
ms.openlocfilehash: fe9ccb5b78d9a60c5b8b2a19fe0818a8e1682f00
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84623119"
---
# <a name="example-of-active-document-containment-office-binder"></a>Exemplo de confinamento do documento ativo: Office Binder

O associador Microsoft Office é um exemplo de um contêiner de documento ativo. Um associador do Office inclui dois painéis principais, como os contêineres normalmente fazem. O painel esquerdo contém ícones que correspondem aos documentos ativos no fichário. Cada documento é chamado de *seção* dentro do fichário. Por exemplo, um associador pode conter documentos do Word, arquivos do PowerPoint, planilhas do Excel e assim por diante.

Clicar em um ícone no painel esquerdo ativa o documento ativo correspondente. O painel direito do fichário exibe o conteúdo do documento ativo selecionado no momento.

Se você abrir e ativar um documento do Word em um fichário, a barra de menus e as barras de ferramentas do Word aparecerão na parte superior do quadro de exibição e você poderá editar o conteúdo do documento usando qualquer comando ou ferramenta do Word. No entanto, a barra de menus é uma combinação das barras de menu do fichário e do Word. Como o Binder e o Word têm menus de **ajuda** , o conteúdo dos respectivos menus é mesclado. Os contêineres de documento ativo, como o Office Binder, fornecem automaticamente a mesclagem do menu **ajuda** ; para obter mais informações, consulte [a mesclagem do menu ajuda](help-menu-merging.md).

Quando você seleciona um documento ativo de outro tipo de aplicativo, a interface do fichário é alterada para acomodar o tipo de aplicativo do documento ativo. Por exemplo, se um associador contiver uma planilha do Excel, você observará que os menus no fichário são alterados quando você seleciona a seção planilha do Excel.

Há, é claro, outros tipos possíveis de contêineres ao lado de fichários. O explorador de arquivos usa a interface típica de painel duplo na qual o painel esquerdo usa um controle de árvore para exibir uma lista hierárquica de diretórios em uma unidade ou rede, enquanto o painel direito exibe os arquivos contidos no diretório atualmente selecionado. Um navegador da Internet-tipo de contêiner (como o Microsoft Internet Explorer), em vez de usar uma interface de painel duplo, geralmente tem um único quadro e fornece navegação usando hiperlinks.

## <a name="see-also"></a>Consulte também

[Contenção de documentos ativos](active-document-containment.md)
