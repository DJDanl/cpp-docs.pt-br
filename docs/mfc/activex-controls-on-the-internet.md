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
ms.openlocfilehash: c019c922a5690d4ead861c40bed3c0c1c76cea28
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62394816"
---
# <a name="activex-controls-on-the-internet"></a>Controles ActiveX na Internet

Controles ActiveX são a versão atualizada da especificação de controle OLE.

>[!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações, consulte [controles ActiveX](activex-controls.md).

Os controles são uma arquitetura principal para o desenvolvimento de componentes de software programável que podem ser usados em uma variedade de diferentes contêineres, incluindo navegadores da Web COM suporte na Internet. Qualquer controle ActiveX pode ser um controle de Internet e adicionar sua funcionalidade a um documento ativo ou fazer parte de uma página da Web. Controles em uma página da Web podem se comunicar entre si usando scripts.

Controles ActiveX não estão limitados à Internet. Um controle ActiveX também pode ser usado em qualquer contêiner, desde que o controle suporta as interfaces necessárias pelo contêiner.

**Controles ActiveX tem várias vantagens, incluindo:**

- As interfaces menos necessárias que controles anteriores de OLE.

- A capacidade de ser sem janelas e sempre ativado.

**Para que seja um controle ActiveX, um controle deve:**

- Suporte a `IUnknown` interface.

- Ser um objeto COM.

- Exportar **DLLRegisterServer** e **DLLUnRegisterServer**.

- Suporte a interfaces adicionais conforme necessário para a funcionalidade.

## <a name="making-your-existing-controls-internet-friendly"></a>Tornando seus controles existentes amigáveis à Internet

Criando um controle que funcione bem em um ambiente de Internet requer uma consideração para as taxas de transmissão relativamente baixa na Internet. Você pode usar os controles existentes; No entanto, há etapas que você deve seguir para diminuir o tamanho do código e fazer com que as propriedades de controle baixar de forma assíncrona.

Para melhorar o desempenho de seus controles, siga estas dicas sobre as considerações de eficiência:

- Implementar as técnicas descritas no artigo [controles ActiveX: Otimização](../mfc/mfc-activex-controls-optimization.md).

- Considere como um controle é instanciado.

- Ser assíncrono não mantenha backup de outros programas.

- Download de dados em pequenos blocos.

   Ao fazer o download de grandes fluxos como bitmaps ou dados de vídeo, acesse dados de um controle assincronamente em cooperação com o contêiner. Recupere os dados de maneira incremental ou progressivo, trabalhando de forma cooperativa com outros controles que também podem recuperar dados. Código também pode ser baixar de forma assíncrona.

- Baixe o código e as propriedades em segundo plano.

- Se tornar a interface do usuário ativa o mais rápido possível.

- Considere como os dados persistentes são armazenados, as propriedades e os dados grandes BLOBs (como dados de imagem ou vídeo um bitmap).

   Os controles com uma quantidade significativa de dados persistentes, como bitmaps grandes ou arquivos AVI, requerem uma atenção especial ao download de método. Um documento ou página pode se tornar visível assim que possível e permitir que o usuário interagir com a página enquanto os controles de recuperam dados em segundo plano.

- Escreva rotinas eficientes para manter o tamanho do código e tempo de execução para baixo.

   Pequeno controles de botão e o rótulo, com apenas alguns bytes de dados persistentes, são adequados para uso no ambiente de Internet e funcionam bem em navegadores.

- Considere a possibilidade de progresso é comunicado ao contêiner.

   Notificar o contêiner de progresso no download assíncrono, incluindo quando o usuário pode começar a interagir com uma página, e quando o download for concluído. O contêiner pode exibir o andamento (como porcentagem concluída) para o usuário.

- Considere como os controles são registrados no computador cliente.

## <a name="creating-a-new-activex-control"></a>Criar um novo controle ActiveX

Ao criar um novo controle usando o Assistente de aplicativo, você pode optar por habilitar o suporte para monikers assíncronos, bem como outras otimizações. Para adicionar suporte para baixar as propriedades de controle de forma assíncrona, siga estas etapas:

#### <a name="to-create-your-project-using-the-mfc-activex-control-wizard"></a>Para criar seu projeto usando o Assistente de controle ActiveX MFC

1. Clique em **New** sobre o **arquivo** menu.

1. Selecione **Assistente de controle ActiveX MFC** do Visual C++, projetos e nomeie o projeto.

1. Sobre o **configurações de controle** página, selecione **carrega as propriedades de forma assíncrona**. Selecionar esta opção define a propriedade de estado pronto e o evento alterado de estado pronto para você.

   Você também pode selecionar outras otimizações, tais como **ativação sem janelas**, que é descrito na [controles ActiveX: Otimização](../mfc/mfc-activex-controls-optimization.md).

1. Escolher **concluir** para criar o projeto.

#### <a name="to-create-a-class-derived-from-cdatapathproperty"></a>Para criar uma classe derivada de CDataPathProperty

1. Criar uma classe derivada de `CDataPathProperty`.

1. Em cada um dos seus arquivos de origem que inclui o arquivo de cabeçalho para o seu controle, adicione o arquivo de cabeçalho para essa classe antes dele.

1. Essa classe, substitua `OnDataAvailable`. Essa função é chamada sempre que os dados estão disponíveis para exibição. Como os dados se torna disponíveis, você pode manipular qualquer forma que escolher, por exemplo, progressivamente renderizá-lo.

   O trecho de código abaixo é um exemplo simples de progressivamente exibindo dados em um controle de edição. Observe o uso do sinalizador **BSCF_FIRSTDATANOTIFICATION** para limpar o controle de edição.

   [!code-cpp[NVC_MFCActiveXControl#1](../mfc/codesnippet/cpp/activex-controls-on-the-internet_1.cpp)]

   Observe que você deve incluir AFXCMN. H para usar o `CListCtrl` classe.

1. Quando o controle geral do estado é alterado (por exemplo, de carregar a inicializado ou interativo do usuário), chamada `COleControl::InternalSetReadyState`. Se o controle tiver uma propriedade de caminho de dados apenas uma, você pode adicionar o código em **BSCF_LASTDATANOTIFICATION** para notificar o contêiner que seu download foi concluído. Por exemplo:

   [!code-cpp[NVC_MFCActiveXControl#2](../mfc/codesnippet/cpp/activex-controls-on-the-internet_2.cpp)]

1. Substitua `OnProgress`. No `OnProgress`, foi passado um número que mostra o intervalo máximo e um número mostrado quão longe o download atual é. Você pode usar esses números para exibir o status, como porcentagem concluída para o usuário.

O procedimento a seguir adiciona uma propriedade para o controle para usar a classe derivada apenas.

#### <a name="to-add-a-property"></a>Para adicionar uma propriedade

1. Na **Class View**, a interface sob o nó de biblioteca com o botão direito e selecione **Add**, em seguida, **adicionar propriedade**. Isso iniciará a **Assistente para adicionar de propriedade**.

1. No **Adicionar Assistente de propriedades**, selecione o **métodos Get/Set** botão de opção, digite o **nome da propriedade**, por exemplo, EditControlText e selecione BSTR como o **Tipo de propriedade**.

1. Clique em **Finalizar**.

1. Declare uma variável de membro de seu `CDataPathProperty`-classe derivada para sua classe de controle ActiveX.

   [!code-cpp[NVC_MFCActiveXControl#3](../mfc/codesnippet/cpp/activex-controls-on-the-internet_3.h)]

1. Implementar o `Get/Set` métodos. Para `Get`, retornar a cadeia de caracteres. Para `Set`, a propriedade e a chamada de carga `SetModifiedFlag`.

   [!code-cpp[NVC_MFCActiveXControl#4](../mfc/codesnippet/cpp/activex-controls-on-the-internet_4.cpp)]

1. Na [DoPropExchange](../mfc/reference/colecontrol-class.md#dopropexchange), adicione a seguinte linha:

   [!code-cpp[NVC_MFCActiveXControl#5](../mfc/codesnippet/cpp/activex-controls-on-the-internet_5.cpp)]

1. Substituir [ResetData](../mfc/reference/cdatapathproperty-class.md#resetdata) para notificar a propriedade para redefinir seu controle, adicionando esta linha:

   [!code-cpp[NVC_MFCActiveXControl#6](../mfc/codesnippet/cpp/activex-controls-on-the-internet_6.cpp)]

## <a name="deciding-whether-to-derive-from-cdatapathproperty-or-ccacheddatapathproperty"></a>Decidir se deve derivar de CDataPathProperty ou CCachedDataPathProperty

O exemplo anterior descreve as etapas para derivar a propriedade do controle de `CDataPathProperty`. Isso é uma boa opção se você estiver baixando os dados em tempo real que muda com frequência, e para os quais você não precisa manter todos os dados, mas apenas o valor atual. Um exemplo é um controle de cotação da bolsa.

Você também pode derivar de `CCachedDataPathProperty`. Nesse caso, os dados baixados são armazenadas em cache em um arquivo de memória. Isso é uma boa opção se você precisar manter os dados baixados — por exemplo, um controle que renderiza progressivamente um bitmap. Nesse caso, a classe tem uma variável de membro que contém seus dados:

`CMemFile m_Cache;`

Em sua classe de controle ActiveX, você pode usar esse arquivo de memória mapeada no `OnDraw` para exibir os dados. Em seu controle ActiveX `CCachedDataPathProperty`-classe, derivada substitui a função de membro `OnDataAvailable` e invalidar o controle, depois de chamar a implementação da classe base.

[!code-cpp[NVC_MFCActiveXControl#7](../mfc/codesnippet/cpp/activex-controls-on-the-internet_7.cpp)]

## <a name="downloading-data-asynchronously-using-activex-controls"></a>Baixando dados de forma assíncrona usando controles ActiveX

Baixar os dados em uma rede deve ser feita de forma assíncrona. A vantagem de fazer então é que, se uma grande quantidade de dados é transferida ou se a conexão estiver lenta, o processo de download não bloquearão outros processos no cliente.

Monikers assíncronos fornecem uma maneira para baixar os dados de forma assíncrona em uma rede. Uma operação de leitura em um moniker assíncrona retorna imediatamente, mesmo se a operação não foi concluída.

Por exemplo, se apenas 10 bytes estão disponíveis e leitura é chamada de forma assíncrona em um arquivo de 1K, leitura não bloqueia, mas retorna com os 10 bytes disponíveis no momento.

Você implementar [monikers assíncronos](../mfc/asynchronous-monikers-on-the-internet.md) usando o `CAsyncMonikerFile` classe. No entanto, os controles ActiveX podem usar o `CDataPathProperty` classe, que é derivada de `CAsyncMonikerFile`, para ajudar a implementar propriedades de controle assíncrono.

## <a name="displaying-a-control-on-a-web-page"></a>Exibição de um controle em uma página da Web

Aqui está um exemplo de uma marca de objeto e atributos para a inserção de um controle em uma página da Web.

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

Se seu controle OLE foi criado com uma versão do Visual C++ antes do 4.2, há etapas que você pode executar para melhorar seu desempenho e aprimorar sua funcionalidade. Para obter uma discussão detalhada sobre essas alterações, consulte [controles ActiveX: Otimização](../mfc/mfc-activex-controls-optimization.md).

Se você estiver adicionando suporte à propriedade assíncrona a um controle existente, você precisará adicionar a propriedade de estado pronto e o `ReadyStateChange` eventos por conta própria. No construtor do controle, adicione:

[!code-cpp[NVC_MFCActiveXControl#8](../mfc/codesnippet/cpp/activex-controls-on-the-internet_8.cpp)]

Você atualizará o estado pronto como seu código é baixado, chamando [COleControl::InternalSetReadyState](../mfc/reference/colecontrol-class.md#internalsetreadystate). Um único lugar, você poderia chamar `InternalSetReadyState` provém a `OnProgress` substituir de `CDataPathProperty`-classe derivada.

## <a name="see-also"></a>Consulte também

[Tarefas de programação da Internet no MFC](../mfc/mfc-internet-programming-tasks.md)<br/>
[Noções básicas de programação da Internet no MFC](../mfc/mfc-internet-programming-basics.md)
