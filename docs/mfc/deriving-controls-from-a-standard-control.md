---
title: Derivando controles a partir de um controle padrão | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- standard controls [MFC], deriving controls from
- common controls [MFC], deriving from
- derived controls
- controls [MFC], derived
- Windows common controls [MFC], deriving from
- standard controls
ms.assetid: a6f84315-7007-4e0e-8576-78be81254802
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: bc1b0b047bc8d594a34177cabf1081c0a1c67970
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46399763"
---
# <a name="deriving-controls-from-a-standard-control"></a>Derivando controles a partir de um controle padrão

Assim como acontece com qualquer [CWnd](../mfc/reference/cwnd-class.md)-derivado da classe, você pode modificar o comportamento de um controle, derivando uma nova classe de uma classe de controle existente.

### <a name="to-create-a-derived-control-class"></a>Para criar uma classe derivada de controle

1. Derive sua classe de uma classe de controle existente e, opcionalmente, substituir os `Create` função de membro para que ele forneça os argumentos necessários para a classe base `Create` função.

1. Fornece funções de membro de manipulador de mensagens e entradas de mapa de mensagem para modificar o comportamento do controle em resposta a mensagens específicas do Windows. Ver [mapeando mensagens para funções](../mfc/reference/mapping-messages-to-functions.md).

1. Fornece novas funções de membro para estender a funcionalidade do controle (opcional).

Usando um controle derivado em uma caixa de diálogo requer trabalho adicional. Os tipos e as posições dos controles em uma caixa de diálogo normalmente são especificadas em um recurso de modelo de caixa de diálogo. Se você criar uma classe de controle derivada, é possível especificá-lo em um modelo de caixa de diálogo, pois o compilador de recurso não sabe nada sobre sua classe derivada.

#### <a name="to-place-your-derived-control-in-a-dialog-box"></a>Para colocar o controle derivado em uma caixa de diálogo

1. Inserir um objeto da classe derivada de controle na declaração de sua classe derivada de caixa de diálogo.

1. Substituir a `OnInitDialog` função de membro em sua classe de caixa de diálogo para chamar o `SubclassDlgItem` a função de membro para o controle derivado.

`SubclassDlgItem` "dinamicamente subclasses" um controle criado de um modelo de caixa de diálogo. Quando um controle dinamicamente em uma subclasse, você se conectar ao Windows, processa algumas mensagens em seu próprio aplicativo e passa as mensagens restantes logon no Windows. Para obter mais informações, consulte o [SubclassDlgItem](../mfc/reference/cwnd-class.md#subclassdlgitem) função de membro da classe `CWnd` no *referência da MFC*. O exemplo a seguir mostra como você pode escrever uma substituição de `OnInitDialog` chamar `SubclassDlgItem`:

[!code-cpp[NVC_MFCControlLadenDialog#3](../mfc/codesnippet/cpp/deriving-controls-from-a-standard-control_1.cpp)]

Como o controle derivado é inserido na classe de caixa de diálogo, ele será construído quando a caixa de diálogo é construída, e ele será destruído quando a caixa de diálogo é destruída. Compare o código com o exemplo na [adicionando o controles By mão](../mfc/adding-controls-by-hand.md).

## <a name="see-also"></a>Consulte também

[Criando e usando controles](../mfc/making-and-using-controls.md)<br/>
[Controles](../mfc/controls-mfc.md)

