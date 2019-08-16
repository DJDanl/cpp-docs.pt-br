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
ms.openlocfilehash: 06c39240d3718f6fbaa15b46abeb8ac9132b5945
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69510867"
---
# <a name="upgrading-an-existing-activex-control"></a>Atualizando um controle ActiveX existente

Os controles ActiveX existentes (anteriormente conhecidos como controles OLE) podem ser usados na Internet sem modificação. No entanto, talvez você queira modificar os controles para melhorar seu desempenho.

> [!IMPORTANT]
> O ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre as tecnologias modernas que substituem o ActiveX, consulte [controles ActiveX](activex-controls.md).

Ao usar seu controle em uma página da Web, há considerações adicionais. O arquivo. ocx e todos os arquivos de suporte devem estar no computador de destino ou ser baixados pela Internet. Isso torna o tamanho do código e o tempo de download uma consideração importante. Os downloads podem ser empacotados em um arquivo. CAB assinado. Você pode marcar seu controle como seguro para script e como seguro para inicializar.

Este artigo aborda os seguintes tópicos:

- [Código de empacotamento para download](#_core_packaging_code_for_downloading)

- [Marcando um controle seguro para script e inicialização](#_core_marking_a_control_safe_for_scripting_and_initializing)

- [Problemas de licenciamento](#_core_licensing_issues)

- [Código de assinatura](#_core_signing_code)

- [Gerenciando a paleta](#_core_managing_the_palette)

- [Comportamento de controle e níveis de segurança do navegador Internet Explorer](#_core_internet_explorer_browser_safety_levels_and_control_behavior)

Você também pode adicionar otimizações, conforme descrito em [controles ActiveX: Otimização](../mfc/mfc-activex-controls-optimization.md). Os monikers podem ser usados para baixar Propriedades e BLOBs grandes de forma assíncrona, conforme descrito em [controles ActiveX na Internet](../mfc/activex-controls-on-the-internet.md).

##  <a name="_core_packaging_code_for_downloading"></a>Código de empacotamento para download

Para obter mais informações sobre esse assunto, consulte [empacotando controles ActiveX](https://docs.microsoft.com//previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa751974%28v%3dvs.85%29).

### <a name="the-codebase-tag"></a>A marca CODEBASE

Os controles ActiveX são inseridos em páginas da `<OBJECT>` Web usando a marca. O `CODEBASE` parâmetro`<OBJECT>` da marca especifica o local do qual baixar o controle. `CODEBASE`pode apontar para vários tipos de arquivo diferentes com êxito.

### <a name="using-the-codebase-tag-with-an-ocx-file"></a>Usando a marca CODEBASE com um arquivo OCX

```
CODEBASE="http://example.microsoft.com/mycontrol.ocx#version=4,
    70,
    0,
    1086"
```

Essa solução baixa apenas o arquivo. ocx do controle e requer que as DLLs de suporte já estejam instaladas no computador cliente. Isso funcionará para controles do Internet Explorer e do MFC ActiveX criados C++com o Visual, porque o Internet Explorer é fornecido com C++ as DLLs de suporte para controles visuais. Se outro navegador da Internet que é compatível com controle ActiveX for usado para exibir esse controle, essa solução não funcionará.

### <a name="using-the-codebase-tag-with-an-inf-file"></a>Usando a marca CODEBASE com um arquivo INF

```
CODEBASE="http://example.microsoft.com/trustme.inf"
```

Um arquivo. inf controlará a instalação de um. ocx e seus arquivos de suporte. Esse método não é recomendado porque não é possível assinar um arquivo. inf (consulte assinar o [código](#_core_signing_code) para ponteiros na assinatura de código).

### <a name="using-the-codebase-tag-with-a-cab-file"></a>Usando a marca CODEBASE com um arquivo CAB

```
CODEBASE="http://example.microsoft.com/acontrol.cab#version=1,
    2,
    0,
    0"
```

Os arquivos de gabinete são a maneira recomendada de empacotar controles ActiveX que usam MFC. Empacotar um controle ActiveX do MFC em um arquivo de gabinete permite que um arquivo. inf seja incluído para controlar a instalação do controle ActiveX e quaisquer DLLs dependentes (como as DLLs do MFC). O uso de um arquivo CAB compacta automaticamente o código para download mais rápido. Se você estiver usando um arquivo. cab para download de componentes, será mais rápido assinar todo o arquivo. cab do que cada componente individual.

### <a name="creating-cab-files"></a>Criando arquivos CAB

As ferramentas para criar arquivos de gabinete agora fazem parte do [SDK do Windows 10](https://dev.windows.com/downloads/windows-10-sdk).

O arquivo de gabinete apontado `CODEBASE` pelo deve conter o arquivo. ocx para seu controle ActiveX e um arquivo. inf para controlar sua instalação. Você cria o arquivo de gabinete especificando o nome do arquivo de controle e um arquivo. inf. Não inclua DLLs dependentes que talvez já existam no sistema neste arquivo de gabinete. Por exemplo, as DLLs do MFC são empacotadas em um arquivo de gabinete separado e referenciadas pelo arquivo de controle. inf.

Para obter detalhes sobre como criar um arquivo CAB, consulte [criando um arquivo CAB](/windows/win32/devnotes/cabinet-api-functions).

### <a name="the-inf-file"></a>O arquivo INF

O exemplo a seguir, India. inf, lista os arquivos de suporte e as informações de versão necessárias para o controle da Índia do MFC. Observe que o local das DLLs do MFC é um site da Microsoft. O Mfc42. cab é fornecido e assinado pela Microsoft.

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

### <a name="the-object-tag"></a>A \<marca de > de objeto

O exemplo a seguir ilustra o `<OBJECT>` uso da marca para empacotar o controle de exemplo da Índia do MFC.

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

Nesse caso, o India. cab conterá dois arquivos, o India. ocx e o India. inf. O comando a seguir criará o arquivo de gabinete:

```
C:\CabDevKit\cabarc.exe -s 6144 N spindial.cab spindial.ocx spindial.inf
```

O `-s 6144` parâmetro reserva espaço no gabinete para assinatura de código.

### <a name="the-version-tag"></a>A marca de versão

Observe aqui que as `#Version` informações especificadas com um arquivo CAB se aplicam ao controle especificado pelo parâmetro *ClassID* da `<OBJECT>` marca.

Dependendo da versão especificada, você pode forçar o download do seu controle. Para obter as especificações completas `OBJECT` da marca, incluindo o parâmetro *codebase* , consulte a referência do W3C.

##  <a name="_core_marking_a_control_safe_for_scripting_and_initializing"></a>Marcando um controle seguro para script e inicialização

Os controles ActiveX usados em páginas da Web devem ser marcados como seguros para scripts e seguros para inicialização se eles estiverem de fato seguros. Um controle seguro não executará a e/s de disco ou acessará a memória ou os registros de um computador diretamente.

Os controles podem ser marcados como seguros para script e seguros para inicialização por meio do registro. Modifique `DllRegisterServer` para adicionar entradas semelhantes às seguintes para marcar o controle como seguro para script e persistência no registro. Um método alternativo é implementar `IObjectSafety`.

Você definirá GUIDs (identificadores globalmente exclusivos) para seu controle para marcá-lo seguro para scripts e para persistência. Os controles que podem ser com segurança no script conterão uma entrada de registro semelhante à seguinte:

```
HKEY_CLASSES_ROOT\Component Categories\{7DD95801-9882-11CF-9FA9-00AA006C42C4}
```

Os controles que podem ser inicializados com segurança de dados persistentes são marcados como seguros para persistência com uma entrada de registro semelhante a:

```
HKEY_CLASSES_ROOT\Component Categories\{7DD95802-9882-11CF-9FA9-00AA006C42C4}
```

Adicione entradas semelhantes às seguintes (substituindo a ID de classe do controle em vez de `{06889605-B8D0-101A-91F1-00608CEAD5B3}`) para associar suas chaves com a seguinte ID de classe:

```
HKEY_CLASSES_ROOT\CLSID\{06889605-B8D0-101A-91F1-00608CEAD5B3}\Implemented Categories\{7DD95801-9882-11CF-9FA9-00AA006C42C4}
HKEY_CLASSES_ROOT\CLSID\{06889605-B8D0-101A-91F1-00608CEAD5B3}\Implemented Categories\{7DD95802-9882-11CF-9FA9-00AA006C42C4}
```

##  <a name="_core_licensing_issues"></a>Problemas de licenciamento

Se você quiser usar um controle licenciado em uma página da Web, deverá verificar se o contrato de licença permite seu uso na Internet e criar um arquivo de pacote de licença (LPK) para ele.

Um controle ActiveX licenciado não será carregado corretamente em uma página HTML se o computador que executa o Internet Explorer não estiver licenciado para usar o controle. Por exemplo, se um controle licenciado foi criado usando o C++Visual, a página HTML que usa o controle será carregada corretamente no computador em que o controle foi criado, mas não será carregada em um computador diferente, a menos que as informações de licenciamento estejam incluídas.

Para usar um controle ActiveX licenciado no Internet Explorer, você deve verificar o contrato de licença do fornecedor para verificar se a licença do controle permite:

- Redistribuição

- Uso do controle na Internet

- Uso do parâmetro codebase

Para usar um controle licenciado em uma página HTML em um computador não licenciado, você deve gerar um arquivo de pacote de licença (LPK). O arquivo LPK contém licenças de tempo de execução para controles licenciados na página HTML. Esse arquivo é gerado via LPK_TOOL. EXE que acompanha o SDK do ActiveX.

#### <a name="to-create-an-lpk-file"></a>Para criar um arquivo LPK

1. Execute LPK_TOOL. EXE em um computador que está licenciado para usar o controle.

1. Na caixa de diálogo **ferramenta de criação de pacote de licença** , na caixa de listagem **controles disponíveis** , selecione cada controle ActiveX licenciado que será usado na página HTML e clique em **Adicionar**.

1. Clique em **salvar & sair** e digite um nome para o arquivo LPK. Isso criará o arquivo LPK e fechará o aplicativo.

#### <a name="to-embed-a-licensed-control-on-an-html-page"></a>Para inserir um controle licenciado em uma página HTML

1. Edite sua página HTML. Na página HTML, insira um \<objeto > marca para o objeto Gerenciador de licenças antes de qualquer outro \<objeto > marcas. O Gerenciador de licenças é um controle ActiveX instalado com o Internet Explorer. Sua ID de classe é mostrada abaixo. Defina a propriedade LPKPath do objeto Gerenciador de licenças como o caminho e o nome do arquivo LPK. Você pode ter apenas um arquivo LPK por página HTML.

```
<OBJECT CLASSID = "clsid:5220cb21-c88d-11cf-b347-00aa00a28331">
<PARAM NAME="LPKPath" VALUE="relative URL to .LPK file">
</OBJECT>
```

1. Insira o \<objeto > marca para seu controle licenciado após a marca do Gerenciador de licenças.

   Por exemplo, uma página HTML que exibe o controle de edição mascarado da Microsoft é mostrada abaixo. A primeira ID de classe é para o controle do Gerenciador de licenças, a segunda ID de classe é para o controle de edição mascarado. Altere as marcas para apontar para o caminho relativo do arquivo. lpk criado anteriormente e adicione uma marca de objeto, incluindo a ID de classe do seu controle.

1. Insira o \<atributo de > de inserção para seu arquivo LPK, se estiver usando o plug-in NCompass ActiveX.

   Se o seu controle pode ser exibido em outros navegadores habilitados ativos — por exemplo, Netscape usando o plug-in do NCompass ActiveX — \<você deve adicionar a sintaxe de > de inserção, conforme mostrado abaixo.

```
<OBJECT CLASSID="clsid:5220cb21-c88d-11cf-b347-00aa00a28331">
<PARAM NAME="LPKPath" VALUE="maskedit.lpk">

<EMBED SRC = "maskedit.LPK">

</OBJECT>
<OBJECT CLASSID="clsid:C932BA85-4374-101B-A56C-00AA003668DC" WIDTH=100 HEIGHT=25>
</OBJECT>
```

Para obter mais informações sobre licenciamento de [controle, consulte controles ActiveX: Licenciamento de um](../mfc/mfc-activex-controls-licensing-an-activex-control.md)controle ActiveX.

##  <a name="_core_signing_code"></a>Código de assinatura

A assinatura de código é projetada para identificar a origem do código e garantir que o código não seja alterado desde que foi assinado. Dependendo das configurações de segurança do navegador, os usuários podem ser avisados antes que o código seja baixado. Os usuários podem optar por confiar em determinados proprietários ou empresas de certificado, caso em que o código assinado por esses certificados confiáveis será baixado sem aviso. O código é assinado digitalmente para evitar a violação.

Verifique se o código final está assinado para que seu controle possa ser baixado automaticamente sem exibir mensagens de aviso de confiança. Para obter detalhes sobre como assinar o código, consulte a documentação sobre Authenticode no SDK do ActiveX e veja [assinando um arquivo CAB](/windows/win32/devnotes/cabinet-api-functions).

Dependendo das configurações de nível de segurança de relação de confiança e navegador, um certificado pode ser exibido para identificar a pessoa ou a empresa de assinatura. Se o nível de segurança for None ou se o proprietário do certificado do controle assinado for confiável, um certificado não será exibido. Consulte [comportamento de controle e níveis de segurança do navegador Internet Explorer](#_core_internet_explorer_browser_safety_levels_and_control_behavior) para obter detalhes sobre como a configuração de segurança do navegador determinará se o seu controle foi baixado e um certificado exibido.

O código de garantias de assinatura digital não foi alterado desde que foi assinado. Um hash do código é obtido e inserido no certificado. Esse hash é posteriormente comparado com um hash do código obtido depois que o código é baixado, mas antes de ser executado. Empresas como a VeriSign podem fornecer chaves públicas e privadas necessárias para assinar o código. O SDK do ActiveX é fornecido com o MakeCert, um utilitário para a criação de certificados de teste.

##  <a name="_core_managing_the_palette"></a>Gerenciando a paleta

Os contêineres determinam a paleta e a disponibilizam como uma propriedade de ambiente, **DISPID_AMBIENT_PALETTE**. Um contêiner (por exemplo, Internet Explorer) escolhe uma paleta que é usada por todos os controles ActiveX em uma página para determinar sua própria paleta. Isso evita a exibição da cintilação e apresenta uma aparência consistente.

Um controle pode ser `OnAmbientPropertyChange` substituído para manipular a notificação de alterações na paleta.

Um controle pode ser `OnGetColorSet` substituído para retornar um conjunto de cores para desenhar a paleta. Os contêineres usam o valor de retorno para determinar se um controle tem reconhecimento de paleta.

Em diretrizes de OCX 96, um controle sempre deve perceber sua paleta em segundo plano.

Os contêineres mais antigos que não usam a propriedade de paleta de ambiente enviarão mensagens WM_QUERYNEWPALETTE e WM_PALETTECHANGED. Um controle pode substituir `OnQueryNewPalette` e `OnPaletteChanged` manipular essas mensagens.

##  <a name="_core_internet_explorer_browser_safety_levels_and_control_behavior"></a>Comportamento de controle e níveis de segurança do navegador Internet Explorer

Um navegador tem opções de nível de segurança, configuráveis pelo usuário. Como as páginas da Web podem conter conteúdo ativo que pode danificar potencialmente o computador de um usuário, os navegadores permitem que o usuário selecione opções para nível de segurança. Dependendo da maneira como um navegador implementa níveis de segurança, um controle pode não ser baixado ou exibirá um certificado ou uma mensagem de aviso para permitir que o usuário escolha em tempo de execução para baixar ou não o controle. O comportamento dos controles ActiveX em níveis de segurança alto, médio e baixo no Internet Explorer é listado abaixo.

### <a name="high-safety-mode"></a>Modo de segurança alta

- Os controles não assinados não serão baixados.

- Os controles assinados exibirão um certificado se não for confiável (um usuário pode escolher uma opção para sempre confiar no código desse proprietário do certificado de agora em diante).

- Somente os controles marcados como seguros terão dados persistentes e/ou poderão ser programáveis.

### <a name="medium-safety-mode"></a>Modo de segurança médio

- Os controles não assinados exibirão um aviso antes do download.

- Os controles assinados exibirão um certificado, se não for confiável.

- Os controles não marcados como seguros exibirão um aviso.

### <a name="low-safety-mode"></a>Modo de segurança baixo

- Os controles são baixados sem aviso.

- O script e a persistência ocorrem sem aviso.

## <a name="see-also"></a>Consulte também

[Tarefas de programação da Internet no MFC](../mfc/mfc-internet-programming-tasks.md)<br/>
[Noções básicas de programação da Internet no MFC](../mfc/mfc-internet-programming-basics.md)<br/>
[Controles ActiveX MFC: licenciar um controle ActiveX](../mfc/mfc-activex-controls-licensing-an-activex-control.md)
