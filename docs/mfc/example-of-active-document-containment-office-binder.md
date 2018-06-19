---
title: 'Exemplo de confinamento do documento ativo: Office Binder | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- active documents [MFC], containers
- examples [MFC], active document containment
- containers [MFC], active document
- active document containers [MFC], examples
- Office Binder [MFC]
- MFC COM, active document containment
ms.assetid: 70dd8568-e8bc-44ac-bf5e-678767efe8e3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b7e4f82840a4c5620762ad57b5b9fa8dd7e62d0a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33345954"
---
# <a name="example-of-active-document-containment-office-binder"></a>Exemplo de confinamento do documento ativo: Office Binder
O Microsoft Office Binder é um exemplo de um contêiner de documento ativo. Um Office Binder inclui dois painéis principais, como contêineres normalmente. O painel esquerdo contém ícones que correspondem aos documentos ativos associador. Cada documento é chamado um *seção* dentro do fichário. Por exemplo, um associador pode conter documentos do Word, arquivos do PowerPoint, planilhas do Excel e assim por diante.  
  
 Clicar em um ícone no painel esquerdo ativa o documento ativo correspondente. O painel direito do fichário, em seguida, exibe o conteúdo do documento ativo atualmente selecionado.  
  
 Se você abrir e ativa um associador de um documento do Word, palavra barra de menus e barras de ferramentas aparecem na parte superior do quadro de exibição e você pode editar o conteúdo do documento usando qualquer comando do Word ou a ferramenta. No entanto, a barra de menu é uma combinação de barras de menus de Binder e do Word. Porque o fichário e palavras têm **ajuda** mesclagem de menus, o conteúdo dos respectivos menus. Fornecer automaticamente aos contêineres de documento ativo como o Office Binder **ajuda** menu mesclando; para obter mais informações, consulte [ajudar a mesclagem de Menu](../mfc/help-menu-merging.md).  
  
 Quando você seleciona um documento ativo de outro tipo de aplicativo, alterações na interface do fichário para acomodar que tipo de aplicativo do documento ativo. Por exemplo, se um associador contiver uma planilha do Excel, você observará que os menus do fichário alterar quando você selecionar a seção de planilha do Excel.  
  
 É claro, há outros possíveis tipos de contêineres ao lado de associadores. Explorador de arquivos usa a interface de painel dual típica em que o painel esquerdo usa um controle de árvore para exibir uma lista hierárquica de diretórios em uma unidade ou a rede, enquanto o painel direito exibe os arquivos contidos na pasta selecionada no momento. Um tipo de navegador da Internet do contêiner (como o Microsoft Internet Explorer), em vez de usar uma interface de dois painéis, geralmente tem uma única estrutura e fornece navegação usando hiperlinks.  
  
## <a name="see-also"></a>Consulte também  
 [Contenção de documentos ativos](../mfc/active-document-containment.md)

