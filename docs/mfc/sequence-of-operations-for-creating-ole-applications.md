---
title: Sequência de operações para criação de aplicativos OLE | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- OLE applications [MFC], creating
- OLE applications [MFC]
- applications [OLE], creating
- applications [OLE]
ms.assetid: 84b0f606-36c1-4253-9cea-44427f0074b9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 412fa5c104d6e85bcaa6ba3703cc8c7ba535f25f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33381203"
---
# <a name="sequence-of-operations-for-creating-ole-applications"></a>Sequência de operações para criação de aplicativos OLE
A tabela a seguir mostra a sua função e a função do framework na criação de vinculação OLE e incorporação de aplicativos. Elas representam as opções disponíveis, em vez de uma sequência de etapas para executar.  
  
### <a name="creating-ole-applications"></a>Criação de aplicativos OLE  
  
|Tarefa|Fazer|A estrutura faz|  
|----------|------------|------------------------|  
|Crie um componente COM.|Execute o Assistente de aplicativo do MFC. Escolha **servidor completo** ou **miniservidor** no **suporte a documentos compostos** guia.|A estrutura gera um aplicativo de esqueleto com capacidade de componente COM habilitada. Todos os recursos COM podem ser transferidos para o seu aplicativo com apenas pequenas modificações.|  
|Crie um aplicativo de contêiner do zero.|Execute o Assistente de aplicativo do MFC. Escolha **contêiner** no **suporte a documentos compostos** guia. Usando o modo de exibição de classe, vá para o editor de código fonte. Preencha o código para suas funções de manipulador de COM.|A estrutura gera uma aplicação esqueleto que pode inserir objetos COM criados por aplicativos de componente (servidor) de COM.|  
|Crie um aplicativo que oferece suporte à automação do zero.|Execute o Assistente de aplicativo do MFC. Escolha **automação** do **recursos avançados** guia. Use modo de exibição de classe para expor métodos e propriedades em seu aplicativo para automação.|A estrutura gera uma aplicação esqueleto que pode ser ativada e automatizada por outros aplicativos.|  
  
## <a name="see-also"></a>Consulte também  
 [Compilando no Framework](../mfc/building-on-the-framework.md)   
 [Sequência de operações para criação de aplicativos MFC](../mfc/sequence-of-operations-for-building-mfc-applications.md)   
 [Sequência de operações para criação de controles ActiveX](../mfc/sequence-of-operations-for-creating-activex-controls.md)   
 [Sequência de operações para criação de aplicativos de banco de dados](../mfc/sequence-of-operations-for-creating-database-applications.md)

