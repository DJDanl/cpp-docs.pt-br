---
title: Atualizando um controle ActiveX existente
ms.date: 09/12/2018
helpviewer_keywords:
- ActiveX controls [MFC], Internet
- LPK files for Internet controls
- safe for scripting and initialization (controls)
- OLE controls [MFC], upgrading to ActiveX
- CAB files, for ActiveX controls
- Internet applications [MFC], ActiveX controls
- Internet applications [MFC], packaging code for download
- upgrading ActiveX controls
- licensing ActiveX controls
ms.assetid: 4d12ddfa-b491-4f9f-a0b7-b51458e05651
ms.openlocfilehash: dfee42369b698956f4f91ab61a1f37e0ef06d9f1
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81754509"
---
# <a name="upgrading-an-existing-activex-control"></a>Atualizando um controle ActiveX existente

Os controles ActiveX existentes (anteriormente controles OLE) podem ser usados na Internet sem modificação. No entanto, você pode querer modificar controles para melhorar seu desempenho.

> [!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre tecnologias modernas que substituim o ActiveX, consulte [ActiveX Controls](activex-controls.md).

Ao usar seu controle em uma página da Web, existem considerações adicionais. O arquivo .ocx e todos os arquivos de suporte devem estar na máquina de destino ou ser baixados através da Internet. Isso torna o tamanho do código e o tempo de download uma consideração importante. Os downloads podem ser embalados em um arquivo .cab assinado. Você pode marcar seu controle como seguro para scripts, e como seguro para inicializar.

Este artigo discute os seguintes tópicos:

- [Código de embalagem para download](#_core_packaging_code_for_downloading)

- [Marcando um cofre de controle para scripting e inicialização](#_core_marking_a_control_safe_for_scripting_and_initializing)

- [Problemas de licenciamento](#_core_licensing_issues)

- [Código de Assinatura](#_core_signing_code)

- [Gerenciando a Paleta](#_core_managing_the_palette)

- [Níveis de segurança e comportamento de controle do navegador do Internet Explorer](#_core_internet_explorer_browser_safety_levels_and_control_behavior)

Você também pode adicionar otimizações, conforme descrito em [ActiveX Controls: Optimization](../mfc/mfc-activex-controls-optimization.md). Os apelidos podem ser usados para baixar propriedades e grandes BLOBs de forma assíncrona, conforme descrito nos [Controles ActiveX na Internet](../mfc/activex-controls-on-the-internet.md).

## <a name="packaging-code-for-downloading"></a><a name="_core_packaging_code_for_downloading"></a>Código de embalagem para download

Para obter mais informações sobre este assunto, consulte [Controles ActiveX de embalagem](/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa751974%28v%3dvs.85%29).

### <a name="the-codebase-tag"></a>A tag CODEBASE

Os controles ActiveX estão incorporados `<OBJECT>` em páginas da Web usando a tag. O `CODEBASE` parâmetro da `<OBJECT>` tag especifica o local a partir do qual baixar o controle. `CODEBASE`pode apontar para vários tipos de arquivos diferentes com sucesso.

### <a name="using-the-codebase-tag-with-an-ocx-file"></a>Usando a tag CODEBASE com um arquivo OCX

```
CODEBASE="http://example.microsoft.com/mycontrol.ocx#version=4,
    70,
    0,
    1086"
```

Esta solução baixa apenas o arquivo .ocx do controle e requer que quaisquer DLLs de suporte já sejam instalados na máquina cliente. Isso funcionará para os controles Internet Explorer e MFC ActiveX construídos com visual C++, porque o Internet Explorer é fornecido com os DLLs de suporte para controles Visual C++. Se outro navegador da Internet que é capaz de controle ActiveX for usado para visualizar esse controle, esta solução não funcionará.

### <a name="using-the-codebase-tag-with-an-inf-file"></a>Usando a tag CODEBASE com um arquivo INF

```
CODEBASE="http://example.microsoft.com/trustme.inf"
```

Um arquivo .inf controlará a instalação de um .ocx e seus arquivos de suporte. Este método não é recomendado porque não é possível assinar um arquivo .inf (consulte [Código de Assinatura](#_core_signing_code) para ponteiros na assinatura de código).

### <a name="using-the-codebase-tag-with-a-cab-file"></a>Usando a tag CODEBASE com um arquivo CAB

```
CODEBASE="http://example.microsoft.com/acontrol.cab#version=1,
    2,
    0,
    0"
```

Os arquivos do gabinete são a maneira recomendada de empacotar controles ActiveX que usam MFC. A embalagem de um controle MFC ActiveX em um arquivo de gabinete permite que um arquivo .inf seja incluído para controlar a instalação do controle ActiveX e quaisquer DLLs dependentes (como os DLLs MFC). O uso de um arquivo CAB comprime automaticamente o código para download mais rápido. Se você estiver usando um arquivo .cab para download de componentes, é mais rápido assinar todo o arquivo .cab do que cada componente individual.

### <a name="creating-cab-files"></a>Criando arquivos CAB

Ferramentas para criar arquivos de gabinete agora fazem parte do [SDK](https://dev.windows.com/downloads/windows-10-sdk)do Windows 10 .

O arquivo de `CODEBASE` gabinete apontado por deve conter o arquivo .ocx para o controle ActiveX e um arquivo .inf para controlar sua instalação. Você cria o arquivo do gabinete especificando o nome do seu arquivo de controle e um arquivo .inf. Não inclua DLLs dependentes que já possam existir no sistema neste arquivo de gabinete. Por exemplo, os DLLs Do MFC são embalados em um arquivo de gabinete separado e referidos pelo arquivo controlando .inf.

Para obter detalhes sobre como criar um arquivo CAB, consulte [Criando um arquivo CAB](/windows/win32/devnotes/cabinet-api-functions).

### <a name="the-inf-file"></a>O arquivo INF

O exemplo a seguir, spindial.inf, lista os arquivos de suporte e as informações de versão necessárias para o controle MFC Spindial. Observe que a localização dos DLLs do MFC é um site da Microsoft. O mfc42.cab é fornecido e assinado pela Microsoft.

```
Contents of spindial.inf:
[mfc42installer]
file-win32-x86=http://activex.microsoft.com/controls/vc/mfc42.cab
[Olepro32.dll] - FileVersion=5,
    0,
    4261,
    0
[Mfc42.dll] - FileVersion=6,
    0,
    8168,
    0
[Msvcrt.dll] - FileVersion=6,
    0,
    8168,
    0
```

### <a name="the-object-tag"></a>A \<tag DE> DO OBJETO

O exemplo a seguir `<OBJECT>` ilustra o uso da tag para empacotar o controle de amostra MFC Spindial.

```
<OBJECT ID="Spindial1" WIDTH=100 HEIGHT=51
    CLASSID="CLSID:06889605-B8D0-101A-91F1-00608CEAD5B3"
    CODEBASE="http://example.microsoft.com/spindial.cab#Version=1,0,0,001">
<PARAM NAME="_Version" VALUE="65536">
<PARAM NAME="_ExtentX" VALUE="2646">
<PARAM NAME="_ExtentY" VALUE="1323">
<PARAM NAME="_StockProps" VALUE="0">
<PARAM NAME="NeedlePosition" VALUE="2">
</OBJECT>
```

Neste caso, spindial.cab conterá dois arquivos, spindial.ocx e spindial.inf. O seguinte comando irá construir o arquivo do gabinete:

```
C:\CabDevKit\cabarc.exe -s 6144 N spindial.cab spindial.ocx spindial.inf
```

O `-s 6144` parâmetro reserva espaço no gabinete para assinatura de código.

### <a name="the-version-tag"></a>A tag de versão

Observe aqui `#Version` que as informações especificadas com um arquivo CAB se aplicam ao `<OBJECT>` controle especificado pelo parâmetro *CLASSID* da tag.

Dependendo da versão especificada, você pode forçar o download do seu controle. Para obter especificações completas da `OBJECT` tag, incluindo o parâmetro *CODEBASE,* consulte a referência W3C.

## <a name="marking-a-control-safe-for-scripting-and-initializing"></a><a name="_core_marking_a_control_safe_for_scripting_and_initializing"></a>Marcando um cofre de controle para scripting e inicialização

Os controles ActiveX usados nas páginas da Web devem ser marcados como seguros para scripts e seguros para inicializar se eles estiverem de fato seguros. Um controle seguro não executará o IO do disco ou acessará a memória ou os registros de uma máquina diretamente.

Os controles podem ser marcados como seguros para scripts e seguros para inicialização através do registro. Modificar `DllRegisterServer` para adicionar entradas semelhantes às seguintes para marcar o controle como seguro para scripting e persistência no registro. Um método alternativo `IObjectSafety`é implementar .

Você definirá GUIDs (Globally Unique Identifiers) para o seu controle para marcá-lo seguro para scripts e para persistência. Os controles que podem ser roteirizados com segurança conterão uma entrada de registro semelhante à seguinte:

```
HKEY_CLASSES_ROOT\Component Categories\{7DD95801-9882-11CF-9FA9-00AA006C42C4}
```

Controles que podem ser inicializados com segurança a partir de dados persistentes são marcados como seguros para persistência com uma entrada de registro semelhante a:

```
HKEY_CLASSES_ROOT\Component Categories\{7DD95802-9882-11CF-9FA9-00AA006C42C4}
```

Adicionar entradas semelhantes às seguintes (substituindo o ID de classe do seu controle no lugar de `{06889605-B8D0-101A-91F1-00608CEAD5B3}`) para associar suas chaves com o seguinte ID de classe:

```
HKEY_CLASSES_ROOT\CLSID\{06889605-B8D0-101A-91F1-00608CEAD5B3}\Implemented Categories\{7DD95801-9882-11CF-9FA9-00AA006C42C4}
HKEY_CLASSES_ROOT\CLSID\{06889605-B8D0-101A-91F1-00608CEAD5B3}\Implemented Categories\{7DD95802-9882-11CF-9FA9-00AA006C42C4}
```

## <a name="licensing-issues"></a><a name="_core_licensing_issues"></a>Problemas de licenciamento

Se você quiser usar um controle licenciado em uma página da Web, você deve verificar se o contrato de licença permite seu uso na Internet e criar um arquivo de pacote de licença (LPK) para ele.

Um controle ActiveX licenciado não será carregado corretamente em uma página HTML se o computador que executa o Internet Explorer não estiver licenciado para usar o controle. Por exemplo, se um controle licenciado foi construído usando o Visual C++, a página HTML usando o controle será carregada corretamente no computador onde o controle foi construído, mas não será carregada em um computador diferente, a menos que as informações de licenciamento sejam incluídas.

Para usar um controle ActiveX licenciado no Internet Explorer, você deve verificar o contrato de licença do fornecedor para verificar se a licença para as licenças de controle permite:

- Redistribuição

- Uso do controle na Internet

- Uso do parâmetro Codebase

Para usar um controle licenciado em uma página HTML em uma máquina não licenciada, você deve gerar um arquivo de pacote de licença (LPK). O arquivo LPK contém licenças de tempo de execução para controles licenciados na página HTML. Este arquivo é gerado via LPK_TOOL. EXE que vem com o ActiveX SDK.

#### <a name="to-create-an-lpk-file"></a>Para criar um arquivo LPK

1. Corra LPK_TOOL. EXE em um computador que é licenciado para usar o controle.

1. Na caixa de diálogo **Ferramenta de Autoragem do pacote de** licença, na caixa de lista Controles **disponíveis,** selecione cada controle ActiveX licenciado que será usado na página HTML e clique em **Adicionar**.

1. Clique **em Salvar & Sair** e digite um nome para o arquivo LPK. Isso criará o arquivo LPK e fechará o aplicativo.

#### <a name="to-embed-a-licensed-control-on-an-html-page"></a>Para incorporar um controle licenciado em uma página HTML

1. Edite sua página HTML. Na página HTML, \<insira uma marca OBJECT> \<para o objeto Gerenciador de licenças antes de qualquer outro OBJETO> tags. O License Manager é um controle ActiveX instalado no Internet Explorer. Seu ID de classe é mostrado abaixo. Defina a propriedade LPKPath do objeto License Manager para o caminho e o nome do arquivo LPK. Você pode ter apenas um arquivo LPK por página HTML.

```
<OBJECT CLASSID = "clsid:5220cb21-c88d-11cf-b347-00aa00a28331">
<PARAM NAME="LPKPath" VALUE="relative URL to .LPK file">
</OBJECT>
```

1. Insira a \<tag OBJECT> para o controle licenciado após a tag Gerenciador de licenças.

   Por exemplo, uma página HTML que exibe o controle Microsoft Masked Edit é mostrada abaixo. O ID de primeira classe é para o controle do Gerenciador de Licenças, o ID de segunda classe é para o controle de edição mascarada. Altere as tags para apontar para o caminho relativo do arquivo .lpk que você criou anteriormente e adicione uma tag de objeto, incluindo o ID de classe para o seu controle.

1. Insira o atributo \<EMBED> para o arquivo LPK, se estiver usando o plug-in NCompass ActiveX.

   Se o seu controle puder ser visualizado em outros navegadores ativos habilitados — por exemplo, \<o Netscape usando o plug-in NCompass ActiveX — você deve adicionar a sintaxe DE> EMBED, conforme mostrado abaixo.

```
<OBJECT CLASSID="clsid:5220cb21-c88d-11cf-b347-00aa00a28331">
<PARAM NAME="LPKPath" VALUE="maskedit.lpk">

<EMBED SRC = "maskedit.LPK">

</OBJECT>
<OBJECT CLASSID="clsid:C932BA85-4374-101B-A56C-00AA003668DC" WIDTH=100 HEIGHT=25>
</OBJECT>
```

Para obter mais informações sobre licenciamento de controle, consulte [ActiveX Controls: Licenciamento de um Controle ActiveX](../mfc/mfc-activex-controls-licensing-an-activex-control.md).

## <a name="signing-code"></a><a name="_core_signing_code"></a>Código de Assinatura

A assinatura de código foi projetada para identificar a fonte do código e garantir que o código não tenha sido alterado desde que foi assinado. Dependendo das configurações de segurança do navegador, os usuários podem ser avisados antes que o código seja baixado. Os usuários podem optar por confiar em certos proprietários de certificados ou empresas, nesse caso, o código assinado por aqueles confiáveis será baixado sem aviso prévio. O código é assinado digitalmente para evitar adulterações.

Certifique-se de que seu código final esteja assinado para que seu controle possa ser baixado automaticamente sem exibir mensagens de aviso de confiança. Para obter detalhes sobre como assinar código, verifique a documentação no Authenticode no ActiveX SDK e consulte [Signing a CAB File](/windows/win32/devnotes/cabinet-api-functions).

Dependendo das configurações de nível de segurança do navegador e da confiança, um certificado pode ser exibido para identificar a pessoa ou empresa assinante. Se o nível de segurança não for nenhum, ou se o proprietário do certificado do controle assinado for confiável, um certificado não será exibido. Consulte [os níveis de segurança e o comportamento de controle](#_core_internet_explorer_browser_safety_levels_and_control_behavior) do navegador do Internet Explorer para obter detalhes sobre como a configuração de segurança do navegador determinará se seu controle foi baixado e um certificado exibido.

A assinatura digital garante que o código não mudou desde que foi assinado. Um hash do código é tomado e incorporado no certificado. Este hash é mais tarde comparado com um hash do código tomado após o código ser baixado, mas antes de ser executado. Empresas como a Verisign podem fornecer chaves públicas e privadas necessárias para assinar o código. O ActiveX SDK é fornecido com o MakeCert, um utilitário para a criação de certificados de teste.

## <a name="managing-the-palette"></a><a name="_core_managing_the_palette"></a>Gerenciando a Paleta

Os recipientes determinam a paleta e a disponibilizam como propriedade ambiental, **DISPID_AMBIENT_PALETTE**. Um contêiner (por exemplo, O Internet Explorer) escolhe uma paleta que é usada por todos os controles ActiveX em uma página para determinar sua própria paleta. Isso evita a cintilação da tela e apresenta uma aparência consistente.

Um controle pode `OnAmbientPropertyChange` substituir para lidar com a notificação de alterações na paleta.

Um controle pode `OnGetColorSet` substituir para retornar um conjunto de cores para desenhar a paleta. Os contêineres usam o valor de retorno para determinar se um controle está ciente da paleta.

De acordo com as diretrizes do OCX 96, um controle deve sempre perceber sua paleta em segundo plano.

Os contêineres mais antigos que não usam a propriedade da paleta ambiente enviarão mensagens WM_QUERYNEWPALETTE e WM_PALETTECHANGED. Um controle pode `OnQueryNewPalette` `OnPaletteChanged` substituir e lidar com essas mensagens.

## <a name="internet-explorer-browser-safety-levels-and-control-behavior"></a><a name="_core_internet_explorer_browser_safety_levels_and_control_behavior"></a>Níveis de segurança e comportamento de controle do navegador do Internet Explorer

Um navegador tem opções para nível de segurança, configuráveis pelo usuário. Como as páginas da Web podem conter conteúdo ativo que pode prejudicar potencialmente o computador de um usuário, os navegadores permitem que o usuário selecione opções para nível de segurança. Dependendo da maneira como um navegador implementa níveis de segurança, um controle pode não ser baixado ou exibir um certificado ou uma mensagem de aviso para permitir que o usuário escolha em tempo de execução se deve ou não baixar o controle. O comportamento dos controles ActiveX em níveis de segurança altos, médios e baixos no Internet Explorer está listado abaixo.

### <a name="high-safety-mode"></a>Modo de alta segurança

- Controles não assinados não serão baixados.

- Os controles assinados exibirão um certificado se não for confiável (um usuário pode escolher uma opção para sempre confiar no código deste proprietário de certificado a partir de agora).

- Somente os controles marcados como seguros terão dados persistentes e/ou serão roteiráveis.

### <a name="medium-safety-mode"></a>Modo de Segurança Média

- Controles não assinados exibirão um aviso antes do download.

- Os controles assinados exibirão um certificado se não forem confiáveis.

- Controles não marcados como seguros exibirão um aviso.

### <a name="low-safety-mode"></a>Modo de baixa segurança

- Os controles são baixados sem aviso.

- O script e a persistência ocorrem sem aviso.

## <a name="see-also"></a>Confira também

[Tarefas de programação da Internet no MFC](../mfc/mfc-internet-programming-tasks.md)<br/>
[Noções básicas de programação da Internet Do MFC](../mfc/mfc-internet-programming-basics.md)<br/>
[Controles MFC ActiveX: licenciando um controle ActiveX](../mfc/mfc-activex-controls-licensing-an-activex-control.md)
