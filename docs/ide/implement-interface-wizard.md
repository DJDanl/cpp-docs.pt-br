---
title: Assistente de Implementação de Interface | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- vc.codewiz.impl.interface.overview
dev_langs:
- C++
helpviewer_keywords:
- Implement Interface Wizard [C++]
ms.assetid: 947c329e-0815-4ca7-835e-c41dfeb75f9e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3e5d48688d271330c1cbcbac69f2e0b0c60ccbe8
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45713746"
---
# <a name="implement-interface-wizard"></a>Assistente de Implementação de Interface
Este assistente implementa uma interface para um objeto COM. As implementações de muitas interfaces estão incluídas nas bibliotecas COM disponíveis no Visual Studio e no Windows. Uma implementação de interface é associada a um objeto quando uma instância do objeto é criada, e ele fornece os serviços oferecidos pelo objeto.  
  
Para ver uma discussão sobre interfaces e implementações, confira [Interfaces e implementações de Interface](/windows/desktop/com/interfaces-and-interface-implementations) no SDK do Windows.  
  
- **Implementar interface de**

   Especifica o local da biblioteca de tipos, com base na qual a interface é criada.  
  
   |Opção|Descrição|  
   |------------|-----------------|  
   |**Projeto**|A biblioteca de tipos faz parte do projeto.|  
   |**Registry**|A biblioteca de tipos é registrada no sistema. As bibliotecas de tipos registradas são listadas em **Bibliotecas de tipos disponíveis**.|  
   |**Arquivo**|A biblioteca de tipos não está necessariamente registrada no sistema, mas está contida em um arquivo. É necessário fornecer o local do arquivo em **Local**.|  
  
- **Bibliotecas de tipos disponíveis**

   Exibe as bibliotecas de tipos disponíveis que contêm as definições de interface que você pode implementar. Se você clicar em **Arquivo** em **Implementar interface de**, essa caixa não ficará disponível para alteração.  
  
- **Local**

   Exibe o local da biblioteca de tipos atualmente selecionada na lista **Bibliotecas de tipos disponíveis**. Se você selecionou **Arquivo** em **Implementar interface de**, clique no botão de reticências para localizar um arquivo que contém a biblioteca de tipos a ser usada.  
  
- **Interfaces**

   Exibe as interfaces cujas definições estão contidas na biblioteca de tipos atualmente selecionada na caixa **Bibliotecas de tipos disponíveis**.  
  
   > [!NOTE]
   > As interfaces que têm o mesmo nome daquelas já implementadas pelo objeto selecionado não são exibidas na caixa **Interfaces**.  
  
   |Botão de transferência|Descrição|  
   |---------------------|-----------------|  
   |**>**|Adiciona à lista **Implementar interfaces** o nome da interface atualmente selecionado na lista **Interfaces**.|  
   |**>>**|Adiciona à lista **Implementar interfaces** todos os nomes de interfaces disponíveis na lista **Interfaces**.|  
   |**\<**|Remove o nome da interface atualmente selecionado na lista **Implementar interfaces**.|  
   |**\<\<**|Remove todos os nomes de interfaces atualmente relacionados na lista **Implementar interfaces**.|  
  
- **Implementar Interfaces**

   Exibe os nomes das interfaces selecionadas para implementação no objeto.  
  
   > [!NOTE]
   > Se você incluir mais de uma interface derivada de `IDispatch` ou se tentar implementar uma interface derivada de outra interface que já está na classe, precisará desfazer a ambiguidade das entradas COM_MAP. Confira [COM_INTERFACE_ENTRY2](../atl/reference/com-interface-entry-macros.md#com_interface_entry2) para obter mais informações.  
  
## <a name="see-also"></a>Consulte também  
 [Implementando uma interface](../ide/implementing-an-interface-visual-cpp.md)