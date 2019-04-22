---
title: Testando propriedades e eventos com contêiner de teste
ms.date: 11/04/2016
helpviewer_keywords:
- testing, test containers
- tstcon32.exe
- debugging ActiveX controls
- test container
- ActiveX Control Test Container
- ActiveX controls [MFC], testing
- properties [MFC], testing
ms.assetid: 626867cf-fe53-4c30-8973-55bb93ef3917
ms.openlocfilehash: 977ef29095e652ab40028a2e8ba7feffabf56418
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58781062"
---
# <a name="testing-properties-and-events-with-test-container"></a>Testando propriedades e eventos com contêiner de teste

O aplicativo de contêiner de teste, fornecido no Visual C++, é um contêiner de controle ActiveX para testar e depurar controles ActiveX. Contêiner de teste permite que o desenvolvedor de controle testar a funcionalidade do controle alterando suas propriedades, invocando seus métodos, e seus eventos acionados. Contêiner de teste pode exibir os logs de notificações de associação de dados e também fornece recursos para testar a funcionalidade de persistência de um controle ActiveX: você pode salvar as propriedades para um fluxo ou subarmazenamento, recarregá-los e examinar os dados de fluxo armazenado. Esta seção descreve como usar os recursos básicos de contêiner de teste. Para obter mais informações, selecione o **ajudar** menu durante a execução do contêiner de teste.

### <a name="to-access-the-activex-control-test-container"></a>Para acessar o contêiner de teste do controle ActiveX

1. Compilar o [TSTCON exemplo: Contêiner de teste do controle ActiveX](../overview/visual-cpp-samples.md).

### <a name="to-test-your-activex-control"></a>Para testar seu controle ActiveX

1. Sobre o **editar** menu do contêiner de teste, clique em **inserir o novo controle**.

1. No **Inserir controle** caixa, selecione o controle desejado e clique em **Okey**. O controle será exibido no contêiner de controle.

    > [!NOTE]
    >  Se o controle não estiver listado na **Inserir controle** diálogo caixa, certifique-se de ter registrado com o **registrar controles** comando do **arquivo** menu do teste Contêiner.

Neste ponto, você pode testar seu controle propriedades ou eventos.

#### <a name="to-test-properties"></a>Para testar as propriedades

1. Sobre o **controle** menu, clique em **invocar métodos**.

1. No **nome do método** lista suspensa, selecione o método PropPut para a propriedade que você deseja testar.

1. Modificar a **o valor do parâmetro** ou **tipo de parâmetro** e clique no **definir valor** botão.

1. Clique em **Invoke** para aplicar o novo valor para o objeto.

   A propriedade agora contém o novo valor.

#### <a name="to-test-events-and-specify-the-destination-of-event-information"></a>Para testar eventos e especificar o destino das informações de evento.

1. Sobre o **opções** menu, clique em **log**.

1. Especifique o destino das informações de evento.

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)<br/>
[Como: Depurar um controle ActiveX](/visualstudio/debugger/how-to-debug-an-activex-control)
