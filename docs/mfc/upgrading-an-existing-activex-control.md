---
title: Atualizando um controle ActiveX existente | Microsoft Docs
ms.custom: ''
ms.date: 09/12/2018
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 48fee88dc991ff58bfb9178e370134ad3cdb11d8
ms.sourcegitcommit: a3c9e7888b8f437a170327c4c175733ad9eb0454
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2018
ms.locfileid: "50204620"
---
# <a name="upgrading-an-existing-activex-control"></a>Atualizando um controle ActiveX existente

Controles ActiveX existente (anteriormente conhecido como controles OLE) pode ser usado na Internet sem modificação. No entanto, você talvez queira modificar controles para melhorar o desempenho.

> [!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre tecnologias modernas que substituem o ActiveX, consulte [controles ActiveX](activex-controls.md).

Ao usar o controle em uma página da Web, há considerações adicionais. O arquivo. ocx e todos os arquivos de suporte devem ser no computador de destino ou ser baixados da Internet. Isso torna o tamanho do código e uma consideração importante de tempo de download. Downloads podem ser empacotados em um arquivo. cab assinados. Você pode marcar seu controle como seguros para script e como seguro para inicialização.

Este artigo discute os seguintes tópicos:

- [Empacotando código para download](#_core_packaging_code_for_downloading)

- [Marcando um controle seguro para script e inicialização](#_core_marking_a_control_safe_for_scripting_and_initializing)

- [Problemas de licenciamento](#_core_licensing_issues)

- [Assinatura de código](#_core_signing_code)

- [Gerenciando a paleta](#_core_managing_the_palette)

- [Níveis de segurança de navegador do Internet Explorer e o comportamento de controle](#_core_internet_explorer_browser_safety_levels_and_control_behavior)

Você também pode adicionar as otimizações, conforme descrito em [controles ActiveX: otimização](../mfc/mfc-activex-controls-optimization.md). Identificadores de origem podem ser usados para baixar as propriedades e grandes BLOBs de forma assíncrona, conforme descrito em [controles ActiveX na Internet](../mfc/activex-controls-on-the-internet.md).

##  <a name="_core_packaging_code_for_downloading"></a> Empacotando código para download

Para obter mais informações sobre este assunto, consulte [controles ActiveX de empacotamento](https://docs.microsoft.com//previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa751974%28v%3dvs.85%29).

### <a name="the-codebase-tag"></a>A marca de base de código

Controles ActiveX são inseridos em páginas da Web usando o `<OBJECT>` marca. O `CODEBASE` parâmetro do `<OBJECT>` marca Especifica o local de onde baixar o controle. `CODEBASE` pode apontar para um número de diferentes tipos de arquivo com êxito.

### <a name="using-the-codebase-tag-with-an-ocx-file"></a>Com a marca de base de código com um arquivo OCX

```
CODEBASE="http://example.microsoft.com/mycontrol.ocx#version=4,
    70,
    0,
    1086"
```

Essa solução baixa somente o arquivo do controle. ocx e exige que todas as DLLs suporte já seja instalado no computador cliente. Isso funcionará para o Internet Explorer e ActiveX do MFC controles criados com o Visual C++, porque o Internet Explorer é fornecido com as DLLs de suporte para controles do Visual C++. Se outro navegador da Internet que é compatível com o controle do ActiveX é usado para exibir esse controle, essa solução não funcionará.

### <a name="using-the-codebase-tag-with-an-inf-file"></a>Usando a marca de base de código com um arquivo INF

```
CODEBASE="http://example.microsoft.com/trustme.inf"
```

Um arquivo. inf irá controlar a instalação de um. ocx e seus arquivos de suporte. Esse método não é recomendado porque não é possível assinar um arquivo. inf (consulte [assinatura de código](#_core_signing_code) para ponteiros na assinatura de código).

### <a name="using-the-codebase-tag-with-a-cab-file"></a>Com a marca de base de código com um arquivo CAB

```
CODEBASE="http://example.microsoft.com/acontrol.cab#version=1,
    2,
    0,
    0"
```

Arquivos de gabinete são a maneira recomendada para controles ActiveX de pacote que usa o MFC. Empacotar um controle ActiveX do MFC em um arquivo de gabinete permite que um arquivo. inf ser incluído no controle da instalação do controle ActiveX e todas as DLLs dependentes (como DLLs do MFC). Usar um arquivo CAB automaticamente compacta o código para download mais rápida. Se você estiver usando um arquivo. cab para download de componente, ele é mais rápido assinar o arquivo. cab inteira que cada componente individual.

### <a name="creating-cab-files"></a>Criação de arquivos CAB

Ferramentas para criar arquivos de gabinete estão agora faz parte dos [SDK do Windows 10](https://dev.windows.com/downloads/windows-10-sdk).

O arquivo de gabinete apontado pelo `CODEBASE` deve conter o arquivo. ocx para seu controle ActiveX e um arquivo. inf para controlar sua instalação. Você cria o arquivo de gabinete, especificando o nome do seu arquivo de controle e um arquivo. inf. Não inclua as DLLs dependentes que possam existir no sistema nesse arquivo de gabinete. Por exemplo, as DLLs do MFC são empacotadas em um arquivo de gabinete separado e referenciadas pelo arquivo. inf controladora.

Para obter detalhes sobre como criar um arquivo CAB, consulte [criando um arquivo CAB](/windows/desktop/devnotes/cabinet-api-functions).

### <a name="the-inf-file"></a>O arquivo INF

O exemplo a seguir, spindial.inf, listas os arquivos de suporte e as informações de versão necessário para o MFC Spindial controlar. Observe que o local para as DLLs do MFC é um site da Microsoft. O mfc42.cab é fornecido e assinado pela Microsoft.

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

### <a name="the-object-tag"></a>O \<objeto > marca

O exemplo a seguir ilustra o uso de `<OBJECT>` marca para empacotar o exemplo de controle MFC Spindial.

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

Nesse caso, spindial.cab conterá dois arquivos, spindial.ocx e spindial.inf. O comando a seguir criará o arquivo de gabinete:

```
C:\CabDevKit\cabarc.exe -s 6144 N spindial.cab spindial.ocx spindial.inf
```

O `-s 6144` parâmetro reserva espaço no arquivo de gabinete para assinatura de código.

### <a name="the-version-tag"></a>A marca de versão

Observe aqui que o `#Version` especificadas com um arquivo CAB de informações se aplicam ao controle especificado pelo *CLASSID* parâmetro do `<OBJECT>` marca.

Dependendo da versão especificada, você pode forçar o download do seu controle. Para as especificações completas do `OBJECT` marca incluindo o *CODEBASE* parâmetro, consulte o W3C referência.

##  <a name="_core_marking_a_control_safe_for_scripting_and_initializing"></a> Marcando um controle seguro para script e inicialização

Controles ActiveX usados nas páginas da Web devem ser marcados como seguro para script e para a inicialização se eles são, na verdade seguros. Um controle seguro não realizar e/s de disco ou acessar a memória ou os registros de uma máquina diretamente.

Controles podem ser marcados como seguro para script e seguro para inicialização através do registro. Modificar `DllRegisterServer` para adicionar entradas semelhantes ao seguinte para marcar o controle como seguro para script e persistência no registro. Um método alternativo é implementar `IObjectSafety`.

Você definirá os GUIDs (identificadores globais exclusivos) para o seu controle para marcá-lo seguro para script e para persistência. Controles que podem ser com segurança incluídos no script conterá uma entrada de registro semelhante ao seguinte:

```
HKEY_CLASSES_ROOT\Component Categories\{7DD95801-9882-11CF-9FA9-00AA006C42C4}
```

Controles que podem ser inicializados com segurança de dados persistentes são marcados como seguros para persistência com uma entrada de registro semelhante a:

```
HKEY_CLASSES_ROOT\Component Categories\{7DD95802-9882-11CF-9FA9-00AA006C42C4}
```

Adicionar entradas semelhantes à seguinte (substituindo seu controle identificação no lugar da classe `{06889605-B8D0-101A-91F1-00608CEAD5B3}`) para associar suas chaves com a ID de classe a seguir:

```
HKEY_CLASSES_ROOT\CLSID\{06889605-B8D0-101A-91F1-00608CEAD5B3}\Implemented Categories\{7DD95801-9882-11CF-9FA9-00AA006C42C4}
HKEY_CLASSES_ROOT\CLSID\{06889605-B8D0-101A-91F1-00608CEAD5B3}\Implemented Categories\{7DD95802-9882-11CF-9FA9-00AA006C42C4}
```

##  <a name="_core_licensing_issues"></a> Problemas de licenciamento

Se você quiser usar um controle licenciado em uma página da Web, você deve verificar que o contrato de licença permite que seu uso na Internet e criar um arquivo de pacote de licença (LPK) para ele.

Um controle ActiveX licenciado não será carregado corretamente em uma página HTML se o computador executando o Internet Explorer não está licenciado para usar o controle. Por exemplo, se um controle licenciado foi criado usando o Visual C++, a página HTML usando o controle será carregado corretamente no computador em que o controle foi criado, mas não será carregado em um computador diferente, a menos que as informações de licenciamento estão incluídas.

Para usar um controle ActiveX licenciado no Internet Explorer, você deve verificar o contrato de licença do fornecedor para verificar o que permite que a licença para o controle:

- Redistribuição

- Uso do controle na Internet

- Uso do parâmetro de base de código

Para usar um controle licenciado em uma página HTML em um computador nonlicensed, você deve gerar um arquivo de pacote de licença (LPK). O arquivo LPK contém as licenças de tempo de execução para controles licenciados na página HTML. Esse arquivo é gerado por meio de LPK_TOOL. EXE que vem com o SDK do ActiveX. Para obter mais informações, consulte o site do MSDN em [ http://msdn.microsoft.com ](http://msdn.microsoft.com).

#### <a name="to-create-an-lpk-file"></a>Para criar um arquivo LPK

1. Execute LPK_TOOL. EXE em um computador que está licenciado para usar o controle.

1. No **interatividade** na caixa de **controles disponíveis** caixa de listagem, selecione cada licenciado controle ActiveX que será usado na página HTML e clique em **Add**.

1. Clique em **salvar e sair** e digite um nome para o arquivo LPK. Isso criará o arquivo LPK e feche o aplicativo.

#### <a name="to-embed-a-licensed-control-on-an-html-page"></a>Para inserir um controle licenciado em uma página HTML

1. Edite sua página HTML. Na página HTML, inserir uma \<objeto > marca para o objeto do Gerenciador de licença antes de qualquer outro \<objeto > marcas. O Gerenciador de licença é um controle ActiveX que é instalado com o Internet Explorer. Sua ID de classe é mostrado abaixo. Defina a propriedade de LPKPath do objeto Gerenciador de licenças para o caminho e nome do arquivo LPK. Você pode ter apenas um arquivo LPK por página HTML.

```
<OBJECT CLASSID = "clsid:5220cb21-c88d-11cf-b347-00aa00a28331">
<PARAM NAME="LPKPath" VALUE="relative URL to .LPK file">
</OBJECT>
```

1. Inserir o \<objeto > marca para o seu controle licenciado após a marca do Gerenciador de licenças.

   Por exemplo, uma página HTML que exibe o controle de edição mascarada da Microsoft é mostrada abaixo. A primeira classe que ID é para o controle do Gerenciador de licenças, a segunda classe que ID é para o controle de edição mascarado. Alterar as marcas para apontar para o caminho relativo do arquivo. lpk que você criou anteriormente e adicione uma marca de objeto, incluindo a ID de classe para o seu controle.

1. Inserir o \<EMBED > atributo para o arquivo LPK, se usar o NCompass ActiveX plug-in.

   Se o controle pode ser exibido em outro ativo habilitado navegadores — por exemplo, o Netscape usando o plug-in do NCompass ActiveX — você deve adicionar o \<EMBED > sintaxe conforme mostrado abaixo.

```
<OBJECT CLASSID="clsid:5220cb21-c88d-11cf-b347-00aa00a28331">
<PARAM NAME="LPKPath" VALUE="maskedit.lpk">

<EMBED SRC = "maskedit.LPK">

</OBJECT>
<OBJECT CLASSID="clsid:C932BA85-4374-101B-A56C-00AA003668DC" WIDTH=100 HEIGHT=25>
</OBJECT>
```

Para obter mais informações sobre o licenciamento de controle, consulte [controles ActiveX: licenciando um controle ActiveX](../mfc/mfc-activex-controls-licensing-an-activex-control.md).

##  <a name="_core_signing_code"></a> Assinatura de código

Assinatura de código foi projetada para identificar a origem do código e garantir que o código não foi alterado desde que ele foi assinado. Dependendo das configurações de segurança do navegador, os usuários podem ser avisados antes que o código é baixado. Os usuários podem optar por confiar determinados os proprietários de certificado ou de empresas, no qual caso código assinado por aqueles confiável será baixado sem aviso. Código é assinado digitalmente para evitar a violação.

Verifique se que seu código final é assinado para que o controle pode ser baixado automaticamente sem exibir mensagens de aviso de relação de confiança. Para obter detalhes sobre como assinar o código, verifique a documentação sobre o Authenticode no SDK do ActiveX e veja [Assinando um arquivo CAB](/windows/desktop/devnotes/cabinet-api-functions).

Dependendo da relação de confiança e o navegador de nível configurações de segurança, um certificado pode ser exibido para identificar a pessoa ou empresa de assinatura. Se o nível de segurança for nenhum, ou se o proprietário do certificado assinado do controle é confiável, um certificado não será exibido. Ver [níveis de segurança de navegador do Internet Explorer e o comportamento de controle](#_core_internet_explorer_browser_safety_levels_and_control_behavior) para obter detalhes sobre como a configuração de segurança do navegador determinará se o controle é baixado e um certificado exibido.

Código de garantias de assinatura digital não foi alterado desde que ele seja assinado. Um hash do código é executado e incorporado no certificado. Posteriormente, esse hash é comparado com um hash do código obtido depois que o código é baixado, mas antes de executar. As empresas como a Verisign podem fornecer chaves públicas e privadas, necessárias para assinar o código. O SDK do ActiveX é fornecido com o MakeCert, um utilitário para a criação de certificados de teste.

##  <a name="_core_managing_the_palette"></a> Gerenciando a paleta

Determinar a paleta de contêineres e disponibilizá-lo como uma propriedade de ambiente **DISPID_AMBIENT_PALETTE**. Um contêiner (por exemplo, o Internet Explorer) escolhe uma paleta que é usada por todos os controles ActiveX em uma página para determinar sua próprias paleta. Isso impede a cintilação de exibição e apresenta uma aparência consistente.

Um controle pode substituir `OnAmbientPropertyChange` para manipular notificações de alterações à paleta.

Um controle pode substituir `OnGetColorSet` para retornar um conjunto para desenhar a paleta de cores. Contêineres usam o valor de retorno para determinar se um controle está ciente de paleta.

Acordo com as diretrizes de 96 OCX, um controle deve sempre percebem a sua paleta em segundo plano.

Contêineres mais antigos que não usam a propriedade palette ambiente enviará mensagens WM_QUERYNEWPALETTE e WM_PALETTECHANGED. Um controle pode substituir `OnQueryNewPalette` e `OnPaletteChanged` para lidar com essas mensagens.

##  <a name="_core_internet_explorer_browser_safety_levels_and_control_behavior"></a> Níveis de segurança de navegador do Internet Explorer e o comportamento de controle

Um navegador tem opções para o nível de segurança configurável pelo usuário. Como as páginas da Web pode conter conteúdo ativo que pode danificar o computador de um usuário, navegadores permitem que o usuário selecione opções para o nível de segurança. Dependendo do modo como um navegador implementa os níveis de segurança, um controle não pode ser baixado em todos os, ou exibirá um certificado ou uma mensagem de aviso para permitir que o usuário escolha se deseja ou não baixar o controle em tempo de execução. O comportamento de controles do ActiveX em níveis de segurança alta, média e baixa no Internet Explorer esteja listado abaixo.

### <a name="high-safety-mode"></a>Modo de alta segurança

- Controles não assinados não serão baixados.

- Controles assinados exibirá um certificado, se não confiável (um usuário pode escolher uma opção para sempre confiar em código desse proprietário do certificado de agora em diante).

- Somente os controles marcados como seguros serão têm dados persistentes e/ou ser programável por script.

### <a name="medium-safety-mode"></a>Modo de segurança média

- Controles não assinados exibirá um aviso antes de baixar.

- Controles assinados exibirá um certificado, se não confiáveis.

- Controles não marcados como seguros exibirá um aviso.

### <a name="low-safety-mode"></a>Modo de segurança baixa

- Controles são baixados sem aviso.

- Script e persistência ocorrerem sem aviso.

## <a name="see-also"></a>Consulte também

[Tarefas de programação da Internet no MFC](../mfc/mfc-internet-programming-tasks.md)<br/>
[Noções básicas de programação da Internet no MFC](../mfc/mfc-internet-programming-basics.md)<br/>
[Controles ActiveX do MFC: licenciando um controle ActiveX](../mfc/mfc-activex-controls-licensing-an-activex-control.md)

