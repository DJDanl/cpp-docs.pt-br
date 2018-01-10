---
title: "Testando propriedades e eventos com contêiner de teste | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- testing, test containers
- tstcon32.exe
- debugging ActiveX controls
- test container
- ActiveX Control Test Container
- ActiveX controls [MFC], testing
- properties [MFC], testing
ms.assetid: 626867cf-fe53-4c30-8973-55bb93ef3917
caps.latest.revision: "13"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 381f4e421b63b2ba48fe649a30e5bf7648b50d27
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="testing-properties-and-events-with-test-container"></a>Testando propriedades e eventos com contêiner de teste
O aplicativo de contêiner de teste, fornecido no Visual C++, é um contêiner de controle ActiveX para testar e depurar os controles ActiveX. Contêiner de teste permite que o desenvolvedor do controle testar a funcionalidade do controle ao alterar suas propriedades, chamar seus métodos e seus eventos acionados. Contêiner de teste pode exibir logs de notificações de associação de dados e também fornece recursos para o teste da funcionalidade de persistência de um controle ActiveX: você pode salvar as propriedades para um fluxo ou subarmazenamento, recarregá-las e examinar os dados de fluxo armazenado. Esta seção descreve como usar os recursos básicos de contêiner de teste. Para obter informações adicionais, selecione o **ajuda** menu durante a execução do contêiner de teste.  
  
### <a name="to-access-the-activex-control-test-container"></a>Para acessar o contêiner de teste do controle ActiveX  
  
1.  Criar o [TSTCON exemplo: contêiner de teste do controle ActiveX](../visual-cpp-samples.md).  
  
### <a name="to-test-your-activex-control"></a>Para testar o controle ActiveX  
  
1.  Sobre o **editar** menu do contêiner de teste, clique em **Inserir novo controle**.  
  
2.  No **Inserir controle** , selecione o controle desejado e clique em **Okey**. O controle será exibido no contêiner do controle.  
  
    > [!NOTE]
    >  Se o controle não estiver listado no **Inserir controle** caixa de diálogo caixa, assegure-se de que você registrou com o **registrar controles** comando o **arquivo** menu do teste Contêiner.  
  
 Agora você pode testar seu controle propriedades ou eventos.  
  
#### <a name="to-test-properties"></a>Para testar as propriedades  
  
1.  Sobre o **controle** menu, clique em **invocar métodos**.  
  
2.  No **nome do método** lista suspensa, selecione o método PropPut para a propriedade que você deseja testar.  
  
3.  Modificar o **o valor do parâmetro** ou **tipo de parâmetro** e clique no **definir valor** botão.  
  
4.  Clique em **Invoke** para aplicar o novo valor para o objeto.  
  
     A propriedade agora contém o novo valor.  
  
#### <a name="to-test-events-and-specify-the-destination-of-event-information"></a>Para testar eventos e especificar o destino de informações de eventos.  
  
1.  Sobre o **opções** menu, clique em **log**.  
  
2.  Especifique o destino das informações de evento.  
  
## <a name="see-also"></a>Consulte também  
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)   
 [Como depurar um controle ActiveX](/visualstudio/debugger/how-to-debug-an-activex-control)

