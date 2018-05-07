---
title: Implementar Interface Assistente | Microsoft Docs
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
ms.openlocfilehash: bf2ddf83b7a03f8d4e01b61f82e46e0d26a5547b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="implement-interface-wizard"></a>Assistente de Implementação de Interface
Este assistente implementa uma interface para um objeto COM. Implementações de várias interfaces são incluídas nas bibliotecas COM disponíveis com o Visual Studio e Windows. Uma implementação de interface está associada um objeto quando uma instância do objeto é criada, e ele fornece os serviços que o objeto oferece.  
  
 Para obter uma discussão das interfaces e implementações, consulte [Interfaces e implementações de Interface](http://msdn.microsoft.com/library/windows/desktop/ms694356) no SDK do Windows.  
  
 **Implementar interface do**  
 Especifica o local da biblioteca de tipo, do qual a interface foi criada.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Projeto**|A biblioteca de tipos é parte do projeto.|  
|**Registry**|A biblioteca de tipos é registrada no sistema. Bibliotecas de tipo registradas são listadas na **bibliotecas de tipo disponível**.|  
|**Arquivo**|A biblioteca de tipos necessariamente não está registrada no sistema, mas está contida em um arquivo. Você deve fornecer o local do arquivo no **local**.|  
  
 **Bibliotecas de tipo disponível**  
 Exibe as bibliotecas de tipo disponível que contém as definições de interface que você pode implementar. Se você clicar em **arquivo** em **implementar a interface de**, essa caixa fica indisponível para alteração.  
  
 **Local**  
 Exibe o local da biblioteca de tipo selecionado no momento o **bibliotecas de tipo disponível** lista. Se você selecionou **arquivo** em **implementar a interface de**, clique no botão de reticências para localizar um arquivo que contém a biblioteca de tipo a ser usado.  
  
 **Interfaces**  
 Exibe as interfaces cujas definições estão contidas na biblioteca de tipos selecionada no momento o **bibliotecas de tipo disponível** caixa.  
  
> [!NOTE]
>  Interfaces que têm o mesmo nome que já implementadas pelo objeto selecionado não são exibidas no **Interfaces** caixa.  
  
|Botão de transferência|Descrição|  
|---------------------|-----------------|  
|**>**|Adiciona o **implementar interfaces** lista o nome da interface selecionado no momento o **Interfaces** lista.|  
|**>>**|Adiciona o **implementar interfaces** lista todos os nomes de interface disponíveis no **Interfaces** lista.|  
|**<**|Remove o nome da interface selecionado no momento o **implementar interfaces** lista.|  
|**<\<**|Remove todos os nomes listados no momento da interface de **implementar interfaces** lista.|  
  
 **Implementar Interfaces**  
 Exibe os nomes das interfaces que você selecionou para implementar em seu objeto.  
  
> [!NOTE]
>  Se você incluir mais de uma interface que é derivada de `IDispatch`, ou se você tentar implementar uma interface que é derivada de outra interface já em sua classe, você deve desfazer a ambiguidade as entradas COM_MAP. Consulte [COM_INTERFACE_ENTRY2](../atl/reference/com-interface-entry-macros.md#com_interface_entry2) para obter mais informações.  
  
## <a name="see-also"></a>Consulte também  
 [Implementando uma Interface](../ide/implementing-an-interface-visual-cpp.md)