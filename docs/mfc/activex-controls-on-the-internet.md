---
title: Controles ActiveX na Internet | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- ActiveX controls [MFC], creating
- ActiveX controls [MFC], Internet
- downloading data with ActiveX controls
- OLE controls [MFC], upgrading to ActiveX
- Internet applications [MFC], ActiveX controls
- networks [MFC], downloading with ActiveX controls
ms.assetid: 7ab943c8-2022-41df-9065-d629b616eeec
caps.latest.revision: "14"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 8c02d807f6b77ca7aa35ffe91b929122a3743be6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="activex-controls-on-the-internet"></a>Controles ActiveX na Internet
Controles ActiveX são a versão atualizada da especificação de controle OLE. Os controles são uma arquitetura principal para o desenvolvimento de componentes de software programável que podem ser usados em uma variedade de diferentes contêineres, incluindo navegadores COM suporte na Internet. Qualquer controle ActiveX pode ser um controle de Internet e pode adicionar sua funcionalidade a um documento ativo ou fazer parte de uma página da Web. Controles em uma página da Web podem se comunicar entre si usando scripts.  
  
 Controles ActiveX não estão limitados à Internet. Um controle ActiveX também pode ser usado em qualquer contêiner, como o controle suporta as interfaces necessárias pelo contêiner.  
  
 **Controles ActiveX tem várias vantagens, incluindo:**  
  
-   As interfaces menos necessárias de controles OLE anteriores.  
  
-   A capacidade de ser sem janelas e ativo sempre no local.  
  
 **Para ser um controle ActiveX, um controle deve:**  
  
-   Suporte a **IUnknown** interface.  
  
-   Ser um objeto COM.  
  
-   Exportar **DLLRegisterServer** e **DLLUnRegisterServer**.  
  
-   Suporte a interfaces adicionais conforme necessário para a funcionalidade.  
  
## <a name="making-your-existing-controls-internet-friendly"></a>Tornando seus controles existentes e compatível com a Internet  
 Criando um controle que funciona bem em um ambiente de Internet requer considerações para as taxas de transmissão relativamente baixa da Internet. Você pode usar os controles existentes; No entanto, há etapas que você deve tomar para diminuir o tamanho do código e fazer com que as propriedades de controle baixar de forma assíncrona.  
  
 Para melhorar o desempenho de seus controles, siga estas dicas sobre considerações de eficiência:  
  
-   Implementar as técnicas descritas no artigo [controles ActiveX: otimização](../mfc/mfc-activex-controls-optimization.md).  
  
-   Considere como um controle é instanciado.  
  
-   Ser assíncrona; não manter os outros programas.  
  
-   Baixe dados em pequenos blocos.  
  
     Ao fazer o download de grandes fluxos como bitmaps ou dados de vídeo, acesse os dados de um controle modo assíncrono em cooperação com o contêiner. Recupere os dados de forma incremental ou progressivo, trabalhando de forma cooperativa com outros controles que também podem recuperar dados. Código também pode ser baixando assincronamente.  
  
-   Baixe o código e as propriedades em segundo plano.  
  
-   Se a interface do usuário ativo mais rápido possível.  
  
-   Considere como os dados persistentes são armazenados, as propriedades e os dados grandes BLOBs (como dados de imagem ou vídeo um bitmap).  
  
     Controles com uma quantidade significativa de dados persistentes, como bitmaps grandes ou arquivos AVI, exigem muita atenção ao método de download. Um documento ou página pode se tornar visível assim que possível e permitir que o usuário interage com a página enquanto controles recuperam dados em segundo plano.  
  
-   Grave rotinas eficientes para manter o tamanho do código e tempo de execução para baixo.  
  
     Pequenos controles de botão e o rótulo, com apenas alguns bytes de dados persistentes, são adequados para uso no ambiente de Internet e trabalho bem em navegadores.  
  
-   Considere a possibilidade de progresso é comunicado para o contêiner.  
  
     Notificar o contêiner de progresso no download assíncrono, incluindo quando o usuário pode começar a interagir com uma página, e quando o download for concluído. O contêiner pode exibir o andamento (como porcentagem concluída) para o usuário.  
  
-   Considere como os controles são registrados no computador cliente.  
  
## <a name="creating-a-new-activex-control"></a>Criar um novo controle ActiveX  
 Ao criar um novo controle usando o Assistente de aplicativo, você pode escolher habilitar o suporte para monikers assíncronos, bem como outras otimizações. Para adicionar suporte para fazer o download de propriedades de controle de forma assíncrona, siga estas etapas:  
  
#### <a name="to-create-your-project-using-the-mfc-activex-control-wizard"></a>Para criar o projeto usando o Assistente de controle ActiveX MFC  
  
1.  Clique em `New` no **arquivo** menu.  
  
2.  Selecione **Assistente de controle ActiveX MFC** do Visual C++ projetos e nomeie o projeto.  
  
3.  Sobre o **configurações de controle** página, selecione **carrega as propriedades de forma assíncrona**. Esta opção define a propriedade de estado pronto e o evento alterado de estado pronto para você.  
  
     Você também pode selecionar outros otimizações, como **ativação sem janelas**, que é descrito em [controles ActiveX: otimização](../mfc/mfc-activex-controls-optimization.md).  
  
4.  Escolha **concluir** para criar o projeto.  
  
#### <a name="to-create-a-class-derived-from-cdatapathproperty"></a>Para criar uma classe derivada de CDataPathProperty  
  
1.  Criar uma classe derivada de `CDataPathProperty`.  
  
2.  Em cada um dos seus arquivos de origem que inclui o arquivo de cabeçalho para o controle, adicione o arquivo de cabeçalho para esta classe antes dele.  
  
3.  Nessa classe, substituir `OnDataAvailable`. Essa função é chamada sempre que os dados estão disponíveis para exibição. Como os dados ficarão disponíveis, você pode manipular como quiser, por exemplo, progressivamente renderizá-lo.  
  
     O trecho de código a seguir é um exemplo simples de progressivamente exibindo dados em um controle de edição. Observe o uso do sinalizador **BSCF_FIRSTDATANOTIFICATION** para limpar o controle de edição.  
  
     [!code-cpp[NVC_MFCActiveXControl#1](../mfc/codesnippet/cpp/activex-controls-on-the-internet_1.cpp)]  
  
     Observe que você deve incluir AFXCMN. H para usar o `CListCtrl` classe.  
  
4.  Quando o controle geral do estado é alterado (por exemplo, de carregamento para inicializado ou interativo do usuário), chamada `COleControl::InternalSetReadyState`. Se o controle tem a propriedade de caminho de dados apenas uma, você pode adicionar código na **BSCF_LASTDATANOTIFICATION** para notificar o contêiner que o download for concluído. Por exemplo:  
  
     [!code-cpp[NVC_MFCActiveXControl#2](../mfc/codesnippet/cpp/activex-controls-on-the-internet_2.cpp)]  
  
5.  Substitua `OnProgress`. Em `OnProgress`, recebem um número mostrando o intervalo máximo e é um número mostrando a distância ao longo de download do atual. Você pode usar esses números para exibir o status como porcentagem concluída para o usuário.  
  
 O procedimento a seguir adiciona uma propriedade para o controle para usar a classe derivada apenas.  
  
#### <a name="to-add-a-property"></a>Para adicionar uma propriedade  
  
1.  Em **exibição de classe**, a interface sob o nó de biblioteca e selecione **adicionar**, em seguida, **adicionar propriedade**. Isso iniciará o **Assistente para adição de propriedade**.  
  
2.  No **Assistente para adição de propriedade**, selecione o **métodos Get/Set** botão de opção, digite o **nome da propriedade**, por exemplo, EditControlText e selecione BSTR como o **Tipo de propriedade**.  
  
3.  Clique em **Finalizar**.  
  
4.  Declare uma variável de membro de sua `CDataPathProperty`-classe derivada para sua classe de controle ActiveX.  
  
     [!code-cpp[NVC_MFCActiveXControl#3](../mfc/codesnippet/cpp/activex-controls-on-the-internet_3.h)]  
  
5.  Implementar o **Get/Set** métodos. Para **obter**, a cadeia de caracteres de retorno. Para `Set`, carregar a propriedade e a chamada `SetModifiedFlag`.  
  
     [!code-cpp[NVC_MFCActiveXControl#4](../mfc/codesnippet/cpp/activex-controls-on-the-internet_4.cpp)]  
  
6.  Em [DoPropExchange](../mfc/reference/colecontrol-class.md#dopropexchange), adicione a seguinte linha:  
  
     [!code-cpp[NVC_MFCActiveXControl#5](../mfc/codesnippet/cpp/activex-controls-on-the-internet_5.cpp)]  
  
7.  Substituir [ResetData](../mfc/reference/cdatapathproperty-class.md#resetdata) para notificar a propriedade para redefinir seu controle adicionando esta linha:  
  
     [!code-cpp[NVC_MFCActiveXControl#6](../mfc/codesnippet/cpp/activex-controls-on-the-internet_6.cpp)]  
  
## <a name="deciding-whether-to-derive-from-cdatapathproperty-or-ccacheddatapathproperty"></a>Decidir se deve derivar de CDataPathProperty ou CCachedDataPathProperty  
 O exemplo anterior descreve etapas para derivar a propriedade do controle de `CDataPathProperty`. Isso é uma boa opção se você estiver baixando dados em tempo real que é alterado com frequência e para os quais você não precisa manter todos os dados, mas apenas o valor atual. Um exemplo é um controle de cotações da bolsa.  
  
 Você também pode derivar de `CCachedDataPathProperty`. Nesse caso, os dados baixados são armazenadas em cache em um arquivo de memória. Isso é uma boa opção se você precisar manter os dados baixados — por exemplo, um controle que processa progressivamente um bitmap. Nesse caso, a classe tem uma variável de membro que contém seus dados:  
  
 `CMemFile m_Cache;`  
  
 Em sua classe de controle ActiveX, você pode usar esse arquivo de memória mapeada em `OnDraw` para exibir os dados. O controle ActiveX `CCachedDataPathProperty`-derivado da classe, substitua a função de membro `OnDataAvailable` e invalidar o controle depois de chamar a implementação da classe base.  
  
 [!code-cpp[NVC_MFCActiveXControl#7](../mfc/codesnippet/cpp/activex-controls-on-the-internet_7.cpp)]  
  
## <a name="downloading-data-asynchronously-using-activex-controls"></a>Baixando dados de forma assíncrona usando controles ActiveX  
 Baixar dados em uma rede deve ser feito assincronamente. A vantagem de fazer assim é que, se uma grande quantidade de dados é transferida ou se a conexão estiver lenta, o processo de download não bloqueará outros processos no cliente.  
  
 Monikers assíncronos fornecem uma maneira de baixar os dados de forma assíncrona em uma rede. Uma operação de leitura em um moniker assíncrona retorna imediatamente, mesmo se a operação não foi concluída.  
  
 Por exemplo, se apenas 10 bytes estão disponíveis e leitura é chamada de forma assíncrona em um arquivo de 1K, leitura não bloqueia, mas retorna os 10 bytes disponíveis no momento.  
  
 Implementar [monikers assíncronos](../mfc/asynchronous-monikers-on-the-internet.md) usando o `CAsyncMonikerFile` classe. No entanto, os controles ActiveX podem usar o `CDataPathProperty` classe, que é derivado de `CAsyncMonikerFile`, para ajudar a implementar propriedades de controle assíncrono.  
  
 O exemplo ASYNDOWN demonstra como configurar um loop assíncrono usando temporizadores para ler os dados. ASYNDOWN é descrita detalhadamente no artigo da Base de dados de Conhecimento "Como: AsyncDown demonstra assíncrona dados Download" (Q177244) e está disponível para download no Microsoft Download Center. (Para obter mais informações sobre como baixar os arquivos do Microsoft Download Center, consulte o artigo "Como para obter arquivos do on-line serviços de suporte Microsoft" (Q119591) na Base de dados de Conhecimento Microsoft.) Você pode encontrar artigos da Base de dados de conhecimento em [http://support.microsoft.com/support](http://support.microsoft.com/support).  
  
 A técnica básica usada em ASYNDOWN é definir um timer **CDataPathProperty::OnDataAvailable** para indicar quando os dados estão disponíveis. Quando a mensagem de timer é recebida, o aplicativo lê em blocos de 128 bytes de dados e preenche um controle de edição. Se os dados não estão disponíveis quando a mensagem de timer é manipulada, o timer está desativado. `OnDataAvailable`ativa o timer se mais dados chegam mais tarde.  
  
## <a name="displaying-a-control-on-a-web-page"></a>Exibição de um controle em uma página da Web  
 Aqui está um exemplo de uma marca de objeto e atributos para a inserção de um controle em uma página da Web.  
  
 `<OBJECT`  
  
 `CLASSID="clsid:FC25B780-75BE-11CF-8B01-444553540000"`  
  
 `CODEBASE="/ie/download/activex/iechart.ocx"`  
  
 `ID=chart1`  
  
 `WIDTH=400`  
  
 `HEIGHT=200`  
  
 `ALIGN=center`  
  
 `HSPACE=0`  
  
 `VSPACE=0`  
  
 `>`  
  
 `<PARAM NAME="BackColor" value="#ffffff">`  
  
 `<PARAM NAME="ForeColor" value="#0000ff">`  
  
 `<PARAM NAME="url" VALUE="/ie/controls/chart/mychart.txt">`  
  
 `</OBJECT>`  
  
## <a name="updating-an-existing-ole-control-to-use-new-activex-control-features"></a>Atualizando um controle OLE existente para usar novos recursos de controle ActiveX  
 Se o controle OLE foi criado com uma versão do Visual C++ antes 4.2, há etapas a que serem seguidas para melhorar o desempenho e aprimorar sua funcionalidade. Para obter uma discussão detalhada sobre essas alterações, consulte [controles ActiveX: otimização](../mfc/mfc-activex-controls-optimization.md).  
  
 Se você estiver adicionando suporte assíncrono de propriedade para um controle existente, você precisará adicionar a propriedade estado pronto e o `ReadyStateChange` eventos por conta própria. No construtor para o controle, adicione:  
  
 [!code-cpp[NVC_MFCActiveXControl#8](../mfc/codesnippet/cpp/activex-controls-on-the-internet_8.cpp)]  
  
 Você atualizará o estado pronto como seu código é baixado chamando [COleControl::InternalSetReadyState](../mfc/reference/colecontrol-class.md#internalsetreadystate). Um único local, você poderia chamar `InternalSetReadyState` é do `OnProgress` substituição do `CDataPathProperty`-classe derivada.  
  

  
## <a name="see-also"></a>Consulte também  
 [Tarefas de programação da Internet MFC](../mfc/mfc-internet-programming-tasks.md)   
 [Noções básicas de programação da Internet no MFC](../mfc/mfc-internet-programming-basics.md)

