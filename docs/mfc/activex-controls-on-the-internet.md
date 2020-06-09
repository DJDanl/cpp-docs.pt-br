---
title: Controles ActiveX na Internet
ms.date: 09/12/2018
helpviewer_keywords:
- ActiveX controls [MFC], creating
- ActiveX controls [MFC], Internet
- downloading data with ActiveX controls
- OLE controls [MFC], upgrading to ActiveX
- Internet applications [MFC], ActiveX controls
- networks [MFC], downloading with ActiveX controls
ms.assetid: 7ab943c8-2022-41df-9065-d629b616eeec
ms.openlocfilehash: f06a6f6f71e922163fd95c59836c50b88b05ed3a
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84616472"
---
# <a name="activex-controls-on-the-internet"></a>Controles ActiveX na Internet

Os controles ActiveX são a versão atualizada da especificação de controle OLE.

>[!IMPORTANT]
> O ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações, consulte [controles ActiveX](activex-controls.md).

Os controles são uma arquitetura primária para o desenvolvimento de componentes de software programáveis que podem ser usados em vários contêineres diferentes, incluindo navegadores da Web COM reconhecimento de COM na Internet. Qualquer controle ActiveX pode ser um controle da Internet e pode adicionar sua funcionalidade a um documento ativo ou fazer parte de uma página da Web. Os controles em uma página da Web podem se comunicar entre si usando scripts.

Os controles ActiveX não são limitados à Internet. Um controle ActiveX também pode ser usado em qualquer contêiner, desde que o controle dê suporte às interfaces exigidas por esse contêiner.

**Os controles ActiveX têm várias vantagens, incluindo:**

- Menos interfaces necessárias do que os controles OLE anteriores.

- A capacidade de ser sem janela e sempre ativa no local.

**Para ser um controle ActiveX, um controle deve:**

- Suporte à `IUnknown` interface.

- Ser um objeto COM.

- Exportar **DllRegisterServer** e **DLLUnRegisterServer**.

- Suporte a interfaces adicionais, conforme necessário para a funcionalidade.

## <a name="making-your-existing-controls-internet-friendly"></a>Tornando seus controles existentes amigáveis para a Internet

A criação de um controle que funcionará bem em um ambiente de Internet requer a consideração das taxas de transmissão relativamente baixas na Internet. Você pode usar os controles existentes; no entanto, há etapas que devem ser seguidas para diminuir o tamanho do código e fazer com que suas propriedades de controle sejam baixadas de forma assíncrona.

Para melhorar o desempenho de seus controles, siga estas dicas sobre considerações de eficiência:

- Implemente as técnicas descritas no artigo [controles ActiveX: otimização](mfc-activex-controls-optimization.md).

- Considere como um controle é instanciado.

- Ser assíncrono; Não mantenha outros programas.

- Baixar dados em blocos pequenos.

   Ao baixar grandes fluxos, como bitmaps ou dados de vídeo, acesse os dados de um controle de forma assíncrona em cooperação com o contêiner. Recupere os dados de maneira incremental ou progressiva, trabalhando de forma cooperativa com outros controles que também podem recuperar dados. O código também pode ser baixado de forma assíncrona.

- Baixe o código e as propriedades em segundo plano.

- Torne a interface do usuário ativa o mais rapidamente possível.

- Considere como os dados persistentes são armazenados, propriedades e BLOBs de dados grandes (como uma imagem de bitmap ou dados de vídeo).

   Controles com quantidades significativas de dados persistentes, como grandes bitmaps ou arquivos AVI, exigem atenção ao download do método. Um documento ou página pode se tornar visível assim que possível e permitir que o usuário interaja com a página enquanto os controles recuperam dados em segundo plano.

- Crie rotinas eficientes para manter o tamanho do código e o tempo de execução inativo.

   Pequenos controles de botão e rótulo, com apenas alguns bytes de dados persistentes, são adequados para uso no ambiente de Internet e funcionam bem dentro de navegadores.

- Considere o andamento da comunicação com o contêiner.

   Notifique o contêiner de progresso no download assíncrono, incluindo quando o usuário pode começar a interagir com uma página e quando o download for concluído. O contêiner pode exibir o andamento (como porcentagem concluída) para o usuário.

- Considere como os controles são registrados no computador cliente.

## <a name="creating-a-new-activex-control"></a>Criando um novo controle ActiveX

Ao criar um novo controle usando o assistente de aplicativo, você pode optar por habilitar o suporte para monikers assíncronos, bem como outras otimizações. Para adicionar suporte para baixar Propriedades de controle de forma assíncrona, siga estas etapas:

#### <a name="to-create-your-project-using-the-mfc-activex-control-wizard"></a>Para criar seu projeto usando o assistente de controle ActiveX do MFC

1. Clique em **novo** no menu **arquivo** .

1. Selecione **Assistente de controle ActiveX do MFC** nos projetos do Visual Studio C++ e nomeie seu projeto.

1. Na página **configurações de controle** , selecione **carrega Propriedades de forma assíncrona**. A seleção dessa opção configura a propriedade estado pronto e o evento de alteração de estado pronto para você.

   Você também pode selecionar outras otimizações, como **ativação sem janela**, que é descrita em [controles ActiveX: otimização](mfc-activex-controls-optimization.md).

1. Escolha **concluir** para criar o projeto.

#### <a name="to-create-a-class-derived-from-cdatapathproperty"></a>Para criar uma classe derivada de CDataPathProperty

1. Crie uma classe derivada de `CDataPathProperty` .

1. Em cada um de seus arquivos de origem que inclui o arquivo de cabeçalho para seu controle, adicione o arquivo de cabeçalho para essa classe antes dela.

1. Nessa classe, substitua `OnDataAvailable` . Essa função é chamada sempre que os dados estiverem disponíveis para exibição. À medida que os dados ficam disponíveis, você pode tratá-los da maneira que escolher, por exemplo, Renderizando-os progressivamente.

   O trecho de código abaixo é um exemplo simples de exibição progressiva de dados em um controle de edição. Observe o uso do sinalizador **BSCF_FIRSTDATANOTIFICATION** para limpar o controle de edição.

   [!code-cpp[NVC_MFCActiveXControl#1](codesnippet/cpp/activex-controls-on-the-internet_1.cpp)]

   Observe que você deve incluir AFXCMN. H para usar a `CListCtrl` classe.

1. Quando o estado geral do controle é alterado (por exemplo, do carregamento para inicializado ou interativo do usuário), chame `COleControl::InternalSetReadyState` . Se o controle tiver apenas uma propriedade de caminho de dados, você poderá adicionar código em **BSCF_LASTDATANOTIFICATION** para notificar o contêiner de que o download foi concluído. Por exemplo:

   [!code-cpp[NVC_MFCActiveXControl#2](codesnippet/cpp/activex-controls-on-the-internet_2.cpp)]

1. Substitua `OnProgress`. No `OnProgress` , você recebe um número que mostra o intervalo máximo e um número mostrando a distância do download atual. Você pode usar esses números para exibir o status, como porcentagem concluída para o usuário.

O próximo procedimento adiciona uma propriedade ao controle para usar a classe que acabou de derivar.

#### <a name="to-add-a-property"></a>Para adicionar uma propriedade

1. Em **modo de exibição de classe**, clique com o botão direito do mouse na interface abaixo do nó da biblioteca e selecione **Adicionar**e, em seguida, **Adicionar Propriedade**. Isso iniciará o **Assistente para adicionar Propriedade**.

1. No **Assistente para adicionar Propriedade**, selecione o botão de opção **definir/obter métodos** , digite o **nome da propriedade**, por exemplo, EditControlText, e selecione BSTR como o tipo de **Propriedade**.

1. Clique em **Concluir**.

1. Declare uma variável de membro de sua classe derivada de sua classe de `CDataPathProperty` controle ActiveX.

   [!code-cpp[NVC_MFCActiveXControl#3](codesnippet/cpp/activex-controls-on-the-internet_3.h)]

1. Implemente os `Get/Set` métodos. Para `Get` , retorne a cadeia de caracteres. Para `Set` , carregue a propriedade e chame `SetModifiedFlag` .

   [!code-cpp[NVC_MFCActiveXControl#4](codesnippet/cpp/activex-controls-on-the-internet_4.cpp)]

1. Em [DoPropExchange](reference/colecontrol-class.md#dopropexchange), adicione a seguinte linha:

   [!code-cpp[NVC_MFCActiveXControl#5](codesnippet/cpp/activex-controls-on-the-internet_5.cpp)]

1. Substitua [ResetData](reference/cdatapathproperty-class.md#resetdata) para notificar a propriedade para redefinir seu controle adicionando esta linha:

   [!code-cpp[NVC_MFCActiveXControl#6](codesnippet/cpp/activex-controls-on-the-internet_6.cpp)]

## <a name="deciding-whether-to-derive-from-cdatapathproperty-or-ccacheddatapathproperty"></a>Decidindo se deve derivar de CDataPathProperty ou CCachedDataPathProperty

O exemplo anterior descreve as etapas para derivar a propriedade do controle de `CDataPathProperty` . Essa é uma boa opção se você estiver baixando dados em tempo real que são alterados com frequência e para os quais não precisa manter todos os dados, mas apenas o valor atual. Um exemplo é um controle de cotação de estoque.

Você também pode derivar de `CCachedDataPathProperty` . Nesse caso, os dados baixados são armazenados em cache em um arquivo de memória. Essa é uma boa opção se você precisar manter todos os dados baixados — por exemplo, um controle que renderiza progressivamente um bitmap. Nesse caso, a classe tem uma variável de membro que contém seus dados:

`CMemFile m_Cache;`

Na sua classe de controle ActiveX, você pode usar esse arquivo de memória mapeada no `OnDraw` para exibir os dados. Na classe derivada do controle ActiveX `CCachedDataPathProperty` , substitua a função membro `OnDataAvailable` e invalida o controle, depois de chamar a implementação da classe base.

[!code-cpp[NVC_MFCActiveXControl#7](codesnippet/cpp/activex-controls-on-the-internet_7.cpp)]

## <a name="downloading-data-asynchronously-using-activex-controls"></a>Baixando dados de forma assíncrona usando controles ActiveX

O download de dados em uma rede deve ser feito de forma assíncrona. A vantagem disso é que, se uma grande quantidade de dados for transferida ou se a conexão estiver lenta, o processo de download não bloqueará outros processos no cliente.

Os monikers assíncronos fornecem uma maneira de baixar dados de forma assíncrona em uma rede. Uma operação de leitura em um moniker assíncrono retorna imediatamente, mesmo que a operação não tenha sido concluída.

Por exemplo, se apenas 10 bytes estiverem disponíveis e a leitura for chamada de forma assíncrona em um arquivo de 1K, a leitura não será bloqueada, mas retornará com os 10 bytes disponíveis no momento.

Você implementa [monikers assíncronos](asynchronous-monikers-on-the-internet.md) usando a `CAsyncMonikerFile` classe. No entanto, os controles ActiveX podem usar a `CDataPathProperty` classe, derivada de `CAsyncMonikerFile` , para ajudar a implementar propriedades de controle assíncrono.

## <a name="displaying-a-control-on-a-web-page"></a>Exibindo um controle em uma página da Web

Aqui está um exemplo de uma marca de objeto e atributos para inserir um controle em uma página da Web.

```xml
<OBJECT
  CLASSID="clsid:FC25B780-75BE-11CF-8B01-444553540000"
  CODEBASE="/ie/download/activex/iechart.ocx"
  ID=chart1
  WIDTH=400
  HEIGHT=200
  ALIGN=center
  HSPACE=0
  VSPACE=0>
  <PARAM NAME="BackColor" value="#ffffff"/>
  <PARAM NAME="ForeColor" value="#0000ff"/>
  <PARAM NAME="url" VALUE="/ie/controls/chart/mychart.txt"/>
</OBJECT>
```

## <a name="updating-an-existing-ole-control-to-use-new-activex-control-features"></a>Atualizando um controle OLE existente para usar novos recursos de controle ActiveX

Se o seu controle OLE foi criado com uma versão do Visual C++ anterior a 4,2, há etapas que você pode seguir para melhorar seu desempenho e aprimorar sua funcionalidade. Para obter uma discussão detalhada sobre essas alterações, consulte [controles ActiveX: otimização](mfc-activex-controls-optimization.md).

Se você estiver adicionando suporte de propriedade assíncrona a um controle existente, será necessário adicionar a propriedade estado pronto e o `ReadyStateChange` evento por conta própria. No construtor do seu controle, adicione:

[!code-cpp[NVC_MFCActiveXControl#8](codesnippet/cpp/activex-controls-on-the-internet_8.cpp)]

Você atualizará o estado pronto à medida que seu código for baixado chamando [COleControl:: InternalSetReadyState](reference/colecontrol-class.md#internalsetreadystate). Um local que você pode chamar `InternalSetReadyState` é da `OnProgress` substituição de `CDataPathProperty` classe derivada.

## <a name="see-also"></a>Consulte também

[Tarefas de programação da Internet no MFC](mfc-internet-programming-tasks.md)<br/>
[Noções básicas de programação na Internet do MFC](mfc-internet-programming-basics.md)
