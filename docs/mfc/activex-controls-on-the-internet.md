---
title: "Controles ActiveX na Internet | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Controles ActiveX [C++], criando"
  - "Controles ActiveX [C++], Internet"
  - "baixando dados com controles ActiveX"
  - "Aplicativos da Internet [C++], Controles ActiveX"
  - "redes [C++], baixando com controles ActiveX"
  - "Controles OLE [C++], atualizando para ActiveX"
ms.assetid: 7ab943c8-2022-41df-9065-d629b616eeec
caps.latest.revision: 14
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Controles ActiveX na Internet
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os controles ActiveX são a versão atualizada da especificação de controlador OLE.  Os controles são uma arquitetura primário para desenvolver os componentes de software programáveis que podem ser usados em uma variedade de contêiner diferentes, incluindo navegadores da Web COM\- reconhecem na Internet.  Todo o controle ActiveX pode ser um controle da Internet e pode adicionar sua funcionalidade para um documento ativo ou fazer parte de uma página da Web.  Os controles em uma página da Web podem se comunicar entre si usando o script.  
  
 Os controles ActiveX não estão limitados à Internet.  Um controle ActiveX também pode ser usado em qualquer contêiner, desde que o controle oferece suporte às interfaces necessárias por esse contêiner.  
  
 **Os controles ActiveX têm várias vantagens, incluindo:**  
  
-   Menos interfaces necessários do que controladores OLE anteriores.  
  
-   A capacidade de ser ativo sem o windows e sempre in\-loco.  
  
 **Para ser um controle ActiveX, um controle deve:**  
  
-   Oferecer suporte à interface de **IUnknown** .  
  
-   É um objeto COM.  
  
-   Exportação **DLLRegisterServer** e **DLLUnRegisterServer**.  
  
-   Interfaces de suporte adicionais conforme necessário para a funcionalidade do.  
  
## Tornando seus controles existentes amigáveis a internet  
 Criar um controle que funcione bem em um ambiente de Internet requer atenção para as taxas de transmissão relativamente baixa na Internet.  Você pode usar os controles existentes; no entanto, há etapas que você deve usar para fazer seu tamanho menor de código e para fazer suas propriedades holdout baixar de forma assíncrona.  
  
 Para melhorar o desempenho dos controles, siga essas dicas em considerações de eficiência:  
  
-   Implementar as técnicas descritas no artigo [Controles ActiveX: Otimização](../mfc/mfc-activex-controls-optimization.md).  
  
-   Considere como um controle é instanciado.  
  
-   É assíncrono; não sustente outros programas.  
  
-   Baixar dados em blocos pequenos.  
  
     Para baixar grandes fluxos como bitmaps ou os dados de vídeos, acessar os dados de controle de forma assíncrona em associação com o contêiner.  Recuperar os dados de forma incremental ou progressiva, cooperativa trabalhando com outros controles que também podem recuperar dados.  O código também pode baixar de forma assíncrona.  
  
-   Código e propriedades de download no plano de fundo.  
  
-   Interface do usuário tornada ativa o mais rápido possível.  
  
-   Considere como os dados persistentes são armazenados, propriedades e grandes blobs de dados \(como os dados de imagem de bitmap ou os vídeo\).  
  
     Os controles com quantidades significativas de dados persistentes, como bitmaps grandes ou arquivos de AVI, a preste atenção baixar o método.  Um documento ou uma página podem se tornar visível o mais rápido possível, e permitem que o usuário interaja com a página quando os controles recupera dados no plano de fundo.  
  
-   Gravar rotinas eficientes para baixo para manter o tamanho e o tempo de execução de código.  
  
     Os controles pequenos do botão e do rótulo, com apenas alguns bytes de dados persistentes, são apropriadas para uso em um ambiente da Internet e funcionam bem navegadores internos.  
  
-   Considere o andamento é anúncio ao contêiner.  
  
     Notifica o contêiner de progresso no download assíncrona, incluindo quando o usuário pode iniciar para interagir com uma página, e quando o carregamento estiver concluído.  O contêiner pode exibir o progresso \(como a porcentagem concluída\) ao usuário.  
  
-   Considere como os controles estão registrados no computador cliente.  
  
## Criando um novo controle ActiveX  
 Ao criar um novo controle usando o assistente do aplicativo, você pode optar por habilitar o suporte a origem assíncronas e outras otimizações.  Para adicionar suporte para download controle propriedades de forma assíncrona, seguem estas etapas:  
  
#### Para criar seu projeto usando o assistente de controle ActiveX de MFC  
  
1.  Clique em `New` no menu de **Arquivo** .  
  
2.  **MFC ActiveX Control Wizard** selecione projetos do Visual C\+\+ e nomeia o seu projeto.  
  
3.  Na página de **Control Settings** , **Loads properties asynchronously**selecione.  Selecione essa opção define configura a propriedade de estado pronto e do estado pronto alterou o evento para você.  
  
     Você também pode selecionar outras otimizações, como **Windowless activation**, que é descrita em [Controles ActiveX: Otimização](../mfc/mfc-activex-controls-optimization.md).  
  
4.  Escolha **Concluir** para criar o projeto.  
  
#### Para criar uma classe derivada de CDataPathProperty  
  
1.  Crie uma classe derivada de `CDataPathProperty`.  
  
2.  Em cada um de seus arquivos de origem que inclui o arquivo de cabeçalho para seu controle, adicione o arquivo de cabeçalho para essa classe antes deles.  
  
3.  Nessa classe, substitua `OnDataAvailable`.  Essa função é chamada sempre que os dados estão disponíveis para exibição.  à medida que os dados se tornam disponíveis, você pode tratam qualquer maneira que você escolher, por exemplo progressivamente renderizando para.  
  
     O trecho de código a seguir é um exemplo simples progressivamente de exibir dados em um controle de edição.  Observe o uso do sinalizador **BSCF\_FIRSTDATANOTIFICATION** limpar o controle de edição.  
  
     [!code-cpp[NVC_MFCActiveXControl#1](../mfc/codesnippet/CPP/activex-controls-on-the-internet_1.cpp)]  
  
     Observe que você deve incluir AFXCMN.H para usar a classe de `CListCtrl` .  
  
4.  Quando o estado do controle total \(por exemplo, da carga em inicializado ou de usuário interativa\), chame `COleControl::InternalSetReadyState`.  Se o controle tiver apenas uma propriedade do caminho de dados, você pode adicionar código em **BSCF\_LASTDATANOTIFICATION** para notificar o contêiner que o download está cheio.  Por exemplo:  
  
     [!code-cpp[NVC_MFCActiveXControl#2](../mfc/codesnippet/CPP/activex-controls-on-the-internet_2.cpp)]  
  
5.  Substitua `OnProgress`.  Em `OnProgress`, você é transmitido para um número que mostra o intervalo máximo e uma exibição número do atraso ao longo de download atual é.  Você pode usar esses números para exibir o status como a porcentagem concluída ao usuário.  
  
 O procedimento a seguir adiciona uma propriedade ao controle para usar a classe derivada apenas.  
  
#### Para adicionar uma propriedade  
  
1.  Em **Modo de Exibição de Classe**, clique com o botão direito do mouse na interface sob o nó da biblioteca e selecione **Adicionar**, em **Adicionar Propriedade**.  Isso iniciará **Add Property Wizard**.  
  
2.  Em **Add Property Wizard**, selecione o botão de opção de **Set\/Get Methods** , digite **Nome da propriedade**, por exemplo, EditControlText, selecione e BSTR como **Tipo de propriedade**.  
  
3.  Clique em **Concluir**.  
  
4.  Declare uma variável do `CDataPathProperty`\- classe derivada de membro à sua classe do controle ActiveX.  
  
     [!code-cpp[NVC_MFCActiveXControl#3](../mfc/codesnippet/CPP/activex-controls-on-the-internet_3.h)]  
  
5.  Implementar os métodos de **Get\/Set** .  Para **Get**, retorna a cadeia de caracteres.  Para `Set`, carregue a propriedade e chame `SetModifiedFlag`.  
  
     [!code-cpp[NVC_MFCActiveXControl#4](../mfc/codesnippet/CPP/activex-controls-on-the-internet_4.cpp)]  
  
6.  Em [DoPropExchange](../Topic/COleControl::DoPropExchange.md), adicione a seguinte linha:  
  
     [!code-cpp[NVC_MFCActiveXControl#5](../mfc/codesnippet/CPP/activex-controls-on-the-internet_5.cpp)]  
  
7.  Substituição [ResetData](../Topic/CDataPathProperty::ResetData.md) para notificar a propriedade para redefinir seu controle adicionando essa linha:  
  
     [!code-cpp[NVC_MFCActiveXControl#6](../mfc/codesnippet/CPP/activex-controls-on-the-internet_6.cpp)]  
  
## Decidindo se derivar de CDataPathProperty ou de CCachedDataPathProperty  
 O exemplo anterior descreve as etapas para derivar a propriedade do controle de `CDataPathProperty`.  Essa é uma boa opção se você estiver baixando os dados em tempo real que são alterados frequentemente, e para a qual você não precisa manter todos os dados, mas apenas o valor atual.  Um exemplo é um controle do relógio de estoque.  
  
 Você também pode derivar de `CCachedDataPathProperty`.  Nesse caso, os dados baixados são armazenados em cachê em um arquivo de memória.  Essa é uma boa opção se você precisar manter todos os dados baixados — por exemplo, um controle que renderiza progressivamente um bitmap.  Nesse caso, a classe tem uma variável de membro que contém seus dados:  
  
 `CMemFile m_Cache;`  
  
 Em sua classe do controle ActiveX, você pode usar esse arquivo mapeado memória em `OnDraw` para exibir os dados.  No controle ActiveX `CCachedDataPathProperty`\- classe derivada, substitua a função de membro `OnDataAvailable` e invalida o controle, depois de chamar a implementação da classe base.  
  
 [!code-cpp[NVC_MFCActiveXControl#7](../mfc/codesnippet/CPP/activex-controls-on-the-internet_7.cpp)]  
  
## Transfere dados que usam de forma assíncrona controles ActiveX  
 Os dados de transferência em uma rede devem ser feitas de forma assíncrona.  A vantagem de fazer isso é que se uma grande quantidade de dados é transferido ou se a conexão for lenta, o processo de download não bloqueará outros processos no cliente.  
  
 Apelidos assíncronas fornecem uma maneira de baixar de forma assíncrona dados em uma rede.  Uma operação de leitura em um moniker assíncrona retorna imediatamente, mesmo se a operação não foi concluída.  
  
 Por exemplo, se somente 10 bytes estão disponíveis e a leitura é chamada de forma assíncrona em um arquivo 1K, a leitura não bloqueia, mas retorna o com os 10 bytes disponíveis atualmente.  
  
 Você implementa [apelidos assíncronas](../mfc/asynchronous-monikers-on-the-internet.md) usando a classe de `CAsyncMonikerFile` .  No entanto, os controles ActiveX podem usar a classe de `CDataPathProperty` , que é derivada de `CAsyncMonikerFile`, para ajudar a implementar propriedades de controle assíncrona.  
  
 O exemplo de ASYNDOWN demonstra como configurar um loop assíncrona usando timers para ler os dados.  ASYNDOWN é descrito em detalhes no artigo da Base de Dados de Conhecimento “HOWTO: AsyncDown demonstra o download assíncrona de dados” \(Q177244\) e está disponível para download no centro de Download da Microsoft. \(Para obter mais informações sobre a transferência do centro de Download da Microsoft, consulte o artigo “como obter arquivos de suporte da Microsoft de serviços online” \(Q119591\) na Base de Dados de Conhecimento Microsoft.\) Você pode localizar artigos da Base de Dados de Conhecimento em um CD\-ROM ou na [http:\/\/support.microsoft.com\/support](http://support.microsoft.com/support)Biblioteca MSDN.  
  
 A técnica básica é usada em ASYNDOWN definir um timer em **CDataPathProperty::OnDataAvailable** para indicar quando os dados estão disponíveis.  Quando a mensagem de timer for recebida, o aplicativo ler em blocos de 128 bytes de dados e preencher um controle de edição.  Se os dados não estão disponíveis quando a mensagem de timer é tratada, o timer está desativado.  `OnDataAvailable` ativa o timer se mais dados chegam mais tarde.  
  
## Exibindo um controle em uma página da Web  
 Eis um exemplo de uma marca e atributos do objeto para inserir um controle em uma página da Web.  
  
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
  
## Atualizando um controlador OLE existente para usar os novos recursos do controle ActiveX  
 Se o controlador OLE foi criado com uma versão do Visual C\+\+ antes de 4,2, haverá etapas que você pode fazer para melhorar seu desempenho e aperfeiçoar sua funcionalidade.  Para obter uma discussão detalhada desses alterado, consulte [Controles ActiveX: Otimização](../mfc/mfc-activex-controls-optimization.md).  
  
 Se você estiver adicionando suporte assíncrona da propriedade a um controle existente, você precisará adicionar a propriedade de estado pronto e o evento de `ReadyStateChange` você mesmo.  No construtor para seu controle, adicione:  
  
 [!code-cpp[NVC_MFCActiveXControl#8](../mfc/codesnippet/CPP/activex-controls-on-the-internet_8.cpp)]  
  
 Você atualizará o estado pronto como o código é baixado chamando [COleControl::InternalSetReadyState](../Topic/COleControl::InternalSetReadyState.md).  Um local em que você pode chamar `InternalSetReadyState` é de substituição de `CDataPathProperty`\- classe derivada de `OnProgress` .  
  
 Em seguida, siga as etapas em [Criando um novo controle ActiveX](#_core_how_do_i_create_a_new_activex_control.3f).  
  
## Consulte também  
 [Tarefas de programação da Internet MFC](../mfc/mfc-internet-programming-tasks.md)   
 [Noções básicas de programação da Internet MFC](../mfc/mfc-internet-programming-basics.md)