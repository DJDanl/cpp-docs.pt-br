---
title: Sequência de operações para criação de aplicativos OLE
ms.date: 11/04/2016
helpviewer_keywords:
- OLE applications [MFC], creating
- OLE applications [MFC]
- applications [OLE], creating
- applications [OLE]
ms.assetid: 84b0f606-36c1-4253-9cea-44427f0074b9
ms.openlocfilehash: b281cbeb4670af0efd232152010fdc90795af103
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50437343"
---
# <a name="sequence-of-operations-for-creating-ole-applications"></a>Sequência de operações para criação de aplicativos OLE

A tabela a seguir mostra a sua função e a função da estrutura na criação de OLE vinculação e incorporação de aplicativos. Elas representam as opções disponíveis, em vez de uma sequência de etapas para executar.

### <a name="creating-ole-applications"></a>Criação de aplicativos OLE

|Tarefa|Você faz|A estrutura faz|
|----------|------------|------------------------|
|Crie um componente COM.|Execute o Assistente de aplicativo do MFC. Escolher **servidor completo** ou **miniservidor** no **suporte de documento composto** guia.|A estrutura gera um aplicativo de esqueleto com capacidade de componente COM habilitada. Todos os recursos do COM podem ser transferidos para o seu aplicativo com apenas pequenas modificações.|
|Crie um aplicativo de contêiner do zero.|Execute o Assistente de aplicativo do MFC. Escolher **recipiente** na **suporte de documento composto** guia. Usando o modo de exibição de classe, vá para o editor de código fonte. Preencha o código para suas funções de manipulador de COM.|A estrutura gera um aplicativo de esqueleto que pode inserir objetos COM criados pelos aplicativos do componente (servidor) COM.|
|Crie um aplicativo que dá suporte à automação do zero.|Execute o Assistente de aplicativo do MFC. Escolher **automação** da **recursos avançados** guia. Use modo de exibição de classe para expor métodos e propriedades em seu aplicativo para a automação.|A estrutura gera um aplicativo de esqueleto que pode ser ativado e automatizado por outros aplicativos.|

## <a name="see-also"></a>Consulte também

[Compilando no Framework](../mfc/building-on-the-framework.md)<br/>
[Sequência de operações para compilar aplicativos MFC](../mfc/sequence-of-operations-for-building-mfc-applications.md)<br/>
[Sequência de operações para criação de controles ActiveX](../mfc/sequence-of-operations-for-creating-activex-controls.md)<br/>
[Sequência de operações para criação de aplicativos de banco de dados](../mfc/sequence-of-operations-for-creating-database-applications.md)

