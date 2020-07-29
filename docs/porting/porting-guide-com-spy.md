---
title: 'Guia de portabilidade: COM Spy'
ms.date: 11/04/2016
ms.assetid: 24aa0d52-4014-4acb-8052-f4e2e4bbc3bb
ms.openlocfilehash: c21049a2faa8bb34ecd1ba75a5beda1db119f0fc
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87230279"
---
# <a name="porting-guide-com-spy"></a>Guia de portabilidade: COM Spy

Este tópico é o segundo de uma série de artigos que demonstra o processo de atualização de projetos mais antigos do Visual Studio C++ para a versão mais recente do Visual Studio. O código de exemplo neste tópico foi compilado pela última vez com o Visual Studio 2005.

## <a name="comspy"></a>COMSpy

COMSpy é um programa que monitora e registra a atividade dos componentes de serviço em um computador. Os componentes de serviço são componentes COM+ que são executados em um sistema e podem ser usados por computadores na mesma rede. Eles são gerenciados pela funcionalidade Serviços de Componentes no Painel de Controle do Windows.

### <a name="step-1-converting-the-project-file"></a>Etapa 1. Convertendo o arquivo de projeto

O arquivo de projeto é convertido facilmente e produz um relatório de migração. Há algumas entradas no relatório que nos informam sobre problemas com os quais talvez seja necessário lidar. Este é um problema reportado (observe que ao longo deste tópico, as mensagens de erro às vezes são abreviadas para facilitar a leitura, por exemplo, para remover os caminhos completos):

```Output
ComSpyAudit\ComSpyAudit.vcproj: MSB8012: $(TargetPath) ('C:\Users\UserName\Desktop\spy\spy\ComSpyAudit\.\XP32_DEBUG\ComSpyAudit.dll') does not match the Librarian's OutputFile property value '.\XP32_DEBUG\ComSpyAudit.dll' ('C:\Users\UserName\Desktop\spy\spy\XP32_DEBUG\ComSpyAudit.dll') in project configuration 'Unicode Debug|Win32'. This may cause your project to build incorrectly. To correct this, please make sure that $(TargetPath) property value matches the value specified in %(Lib.OutputFile).
```

Um dos problemas frequentes na atualização de projetos é que a configuração de **arquivo_de_saída do vinculador** na caixa de diálogo Propriedades do projeto pode precisar ser revisada. Para projetos anteriores ao Visual Studio 2010, o OutputFile será uma configuração que o assistente de conversão automática com a qual o assistente tem problemas se estiver definida com um valor não padrão. Nesse caso, os caminhos para os arquivos de saída foram definidos para uma pasta não padrão, XP32_DEBUG. Para obter mais informações sobre esse erro, consultamos uma [postagem no blog](https://devblogs.microsoft.com/cppblog/visual-studio-2010-c-project-upgrade-guide/) relacionada à atualização de projeto do Visual Studio C++ 2010, que era a atualização que envolvia a alteração do vcbuild para msbuild, uma mudança significativa. De acordo com essas informações, o valor padrão da configuração de **Arquivo de Saída** ao criar um novo projeto é `$(OutDir)$(TargetName)$(TargetExt)`, mas ele não é definido durante a conversão, pois os projetos convertidos não conseguem verificar se está tudo certo. No entanto, vamos tentar aplicar isso a OutputFile e ver se funciona.  Funciona, portanto, podemos continuar. Se não houver nenhum motivo específico para usar uma pasta de saída não padrão, será recomendável usar o local padrão. Nesse caso, escolhemos deixar o local de saída como o não padrão durante o processo de portabilidade e atualização. `$(OutDir)` é resolvido para a pasta XP32_DEBUG na configuração de **Depuração** e para a pasta ReleaseU para a configuração de **Versão**.

### <a name="step-2-getting-it-to-build"></a>Etapa 2. Realização do build

Ao compilar o projeto portado, ocorrem vários erros e avisos.

`ComSpyCtl` não é compilado devido a este erro do compilador:

```Output
atlcom.h(611): error C2664: 'HRESULT CComSpy::IPersistStreamInit_Save(LPSTREAM,BOOL,ATL::ATL_PROPMAP_ENTRY *)': cannot convert argument 3 from 'const ATL::ATL_PROPMAP_ENTRY *' to 'ATL::ATL_PROPMAP_ENTRY *'atlcom.h(611): note: Conversion loses qualifiersatlcom.h(608): note: while compiling class template member function 'HRESULT ATL::IPersistStreamInitImpl<CComSpy>::Save(LPSTREAM,BOOL)'\spy\spy\comspyctl\ccomspy.h(28): note: see reference to class template instantiation 'ATL::IPersistStreamInitImpl<CComSpy>' being compiled
```

O erro referencia o método `Save` na classe `IPersistStreamInitImpl` em atlcom.h.

```cpp
STDMETHOD(Save)(_Inout_ LPSTREAM pStm, _In_ BOOL fClearDirty)
{
     T* pT = static_cast<T*>(this);
     ATLTRACE(atlTraceCOM, 2, _T("IPersistStreamInitImpl::Save\n"));
     return pT->IPersistStreamInit_Save(pStm, fClearDirty, T::GetPropertyMap());
}
```

O problema é que uma conversão que uma versão mais antiga do compilador aceito não é mais válida. Para estar em conformidade com o padrão C++, alguns códigos que anteriormente eram permitidos não são mais permitidos. Nesse caso, não é seguro passar um ponteiro não const para uma função que espera um ponteiro const.  A solução é encontrar a declaração de `IPersistStreamInit_Save` na classe `CComSpy` e adicionar o modificador const ao terceiro parâmetro.

```cpp
HRESULT CComSpy::IPersistStreamInit_Save(LPSTREAM pStm, BOOL /* fClearDirty */, const ATL_PROPMAP_ENTRY* pMap)
```

E uma alteração similar para `IPersistStreamInit_Load`.

```cpp
HRESULT IPersistStreamInit_Load(LPSTREAM pStm, const ATL_PROPMAP_ENTRY* pMap);
```

O próximo erro lida com o registro.

```Output
error MSB3073: The command "regsvr32 /s /c "C:\Users\username\Desktop\spy\spy\ComSpyCtl\.\XP32_DEBUG\ComSpyCtl.lib"error MSB3073: echo regsvr32 exec. time > ".\XP32_DEBUG\regsvr32.trg"error MSB3073:error MSB3073: :VCEnd" exited with code 3.
```

Esse comando pós-build não é mais necessário. Em vez disso, simplesmente removemos o comando de Build personalizado e especificamos as configurações do **vinculador** para registrar a saída.

### <a name="dealing-with-warnings"></a>Lidando com os avisos

O projeto produz os seguintes avisos de vinculador.

```Output
warning LNK4075: ignoring '/EDITANDCONTINUE' due to '/SAFESEH' specification
```

A opção do compilador `/SAFESEH` não é útil no modo de depuração, que é quando `/EDITANDCONTINUE` é útil, portanto, a correção aqui é desabilitar `/SAFESEH` apenas para configurações de **Depuração**. Para fazer isso na caixa de diálogo de propriedade, podemos abrir a caixa de diálogo de propriedade do projeto que gera esse erro e primeiro definir a **Configuração** para **Depurar** (na verdade, **Depurar Unicode**) e, em seguida, na seção **Vinculador Avançado**, redefinir a propriedade **A imagem tem manipuladores de exceção seguros** para **Não** (`/SAFESEH:NO`).

O compilador avisa que `PROP_ENTRY_EX` foi preterido. Ele não é seguro e o substituto recomendado é `PROP_ENTRY_TYPE_EX`.

```cpp
BEGIN_PROPERTY_MAP(CComSpy)
     PROP_ENTRY_EX( "LogFile", DISPID_LOGFILE, CLSID_ComSpyPropPage, IID_IComSpy)
     PROP_ENTRY_EX( "ShowGridLines", DISPID_GRIDLINES, CLSID_ComSpyPropPage, IID_IComSpy)
     PROP_ENTRY_EX( "Audit", DISPID_AUDIT, CLSID_ComSpyPropPage, IID_IComSpy)
     PROP_ENTRY_EX( "ColWidth", DISPID_COLWIDTH, CLSID_ComSpyPropPage, IID_IComSpy)
     PROP_PAGE(CLSID_StockFontPage)
END_PROPERTY_MAP()
```

Alteramos o código em ccomspy.h da mesma forma, adicionando tipos COM conforme apropriado.

```cpp
BEGIN_PROPERTY_MAP(CComSpy)
     PROP_ENTRY_TYPE_EX( "LogFile", DISPID_LOGFILE, CLSID_ComSpyPropPage, IID_IComSpy, VT_BSTR)
     PROP_ENTRY_TYPE_EX( "ShowGridLines", DISPID_GRIDLINES, CLSID_ComSpyPropPage, IID_IComSpy, VT_BOOL)
     PROP_ENTRY_TYPE_EX( "Audit", DISPID_AUDIT, CLSID_ComSpyPropPage, IID_IComSpy, VT_BOOL)
     PROP_ENTRY_TYPE_EX( "ColWidth", DISPID_COLWIDTH, CLSID_ComSpyPropPage, IID_IComSpy, VT_UINT)
     PROP_PAGE(CLSID_StockFontPage)
END_PROPERTY_MAP()
```

Estamos chegando aos últimos avisos, que também são causados por verificações de conformidade do compilador mais estritas:

```Output
\spy\comspyctl\usersub.h(70): warning C4457: declaration of 'var' hides function parameter\spy\comspyctl\usersub.h(48): note: see declaration of 'var'\spy\comspyctl\usersub.h(94): warning C4018: '<': signed/unsigned mismatch  ComSpy.cpp\spy\comspyctl\comspy.cpp(186): warning C4457: declaration of 'bHandled' hides function parameter\spy\spy\comspyctl\comspy.cpp(177): note: see declaration of 'bHandled'
```

O aviso C4018 vem deste código:

```cpp
for (i=0;i<lCount;i++)
    CoTaskMemFree(pKeys[i]);
```

O problema é `i` declarado como `UINT` e `lCount` é declarado como **`long`** , portanto, a incompatibilidade de sinal/não assinado. Seria inconveniente alterar o tipo de `lCount` para `UINT` , já que ele obtém seu valor `IMtsEventInfo::get_Count` , que usa o tipo **`long`** e não está no código do usuário. Então adicionamos uma conversão ao código. Uma conversão em estilo C faria para uma conversão numérica, como esta, mas **`static_cast`** é o estilo recomendado.

```cpp
for (i=0;i<static_cast<UINT>(lCount);i++)
    CoTaskMemFree(pKeys[i]);
```

Esses avisos são casos em que uma variável foi declarada em uma função que tem um parâmetro com o mesmo nome, levando a um código potencialmente confuso. Corrigimos isso alterando os nomes das variáveis locais.

### <a name="step-3-testing-and-debugging"></a>Etapa 3. Testando e depurando

Testamos o aplicativo primeiro executando por meio de vários menus e comandos e, em seguida, fechando o aplicativo. O único problema observado foi uma asserção de depuração ao fechar o aplicativo. O problema apareceu no destruidor de `CWindowImpl`, uma classe base do objeto `CSpyCon`, o componente COM principal do aplicativo. A falha de asserção ocorreu no código a seguir no atlwin.h.

```cpp
virtual ~CWindowImplRoot()
{
     #ifdef _DEBUG
     if(m_hWnd != NULL)// should be cleared in WindowProc
     {
          ATLTRACE(atlTraceWindowing, 0, _T("ERROR - Object deleted before window was destroyed\n"));
          ATLASSERT(FALSE);
     }
     #endif //_DEBUG
}
```

O `hWnd` normalmente é definido como zero na função `WindowProc`, mas isso não aconteceu porque em vez do `WindowProc` padrão, um manipulador personalizado foi chamado para a mensagem do Windows (WM_SYSCOMMAND) que fecha a janela. O manipulador personalizado não estava definindo o `hWnd` como zero. Uma observação do código semelhante na classe `CWnd` do MFC mostra que quando uma janela está sendo destruída, `OnNcDestroy` é chamado e, no MFC, a documentação recomenda que ao substituir `CWnd::OnNcDestroy`, o `NcDestroy` base deve ser chamado para garantir que as operações de limpeza certas ocorram, incluindo a separação do identificador da janela em relação à janela ou, em outras palavras, a configuração de `hWnd` para zero. Essa declaração pode ter sido disparada na versão original do exemplo também, uma vez que o mesmo código de asserção estava presente na versão antiga do atlwin.h.

Para testar a funcionalidade do aplicativo, criamos um **componente de serviço** usando o modelo de projeto ATL, optamos por adicionar suporte a com+ no assistente de projeto do ATL. Se você ainda não trabalhou com componentes atendidos, não é difícil criar um e obter um registrado e disponível no sistema ou na rede para que outros aplicativos usem. O aplicativo COM Spy foi projetado para monitorar a atividade dos componentes de serviço como um auxílio de diagnóstico.

Em seguida, adicionamos uma classe, escolhemos o Objeto ATL e especificamos o nome do objeto como `Dog`. Em seguida, em dog.h e dog.cpp, adicionamos a implementação.

```cpp
STDMETHODIMP CDog::Wag(LONG* lDuration)
{
    // TODO: Add your implementation code here
    *lDuration = 100l;
    return S_OK;
}
```

Em seguida, nós o criamos e o registramos (você precisará executar o Visual Studio como administrador) e o ativou usando o aplicativo de **componente de serviço** no painel de controle do Windows. Criamos um projeto Windows Forms do C#, arrastamos um botão para o formulário da caixa de ferramentas e clicamos duas vezes em um manipulador de eventos de clique. Adicionamos o seguinte código para criar uma instância do componente `Dog`.

```cpp
private void button1_Click(object sender, EventArgs e)
{
    ATLProjectLib.Dog dog1 = new ATLProjectLib.Dog();
    dog1.Wag();
}
```

Ele foi executado sem problemas. E com o COM Spy em funcionamento e configurado para monitorar o componente `Dog`, vários dados são exibidos mostrando a atividade.

## <a name="see-also"></a>Confira também

[Portabilidade e atualização: exemplos e estudos de caso](../porting/porting-and-upgrading-examples-and-case-studies.md)<br/>
[Próximo exemplo: Spy++](../porting/porting-guide-spy-increment.md)<br/>
[Exemplo anterior: Scribble do MFC](../porting/porting-guide-mfc-scribble.md)
