---
title: "Guia de portabilidade: COM Spy | Microsoft Docs"
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
ms.assetid: 24aa0d52-4014-4acb-8052-f4e2e4bbc3bb
caps.latest.revision: 10
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Guia de portabilidade: COM Spy
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico é o segundo de uma série de artigos que demonstra o processo de atualização de projetos do Visual C\+\+ anteriores à versão mais recente do Visual Studio.  O exemplo de código neste tópico última compilação com o Visual Studio 2005.  
  
## COMSpy  
 COMSpy é um programa que monitora e registra a atividade dos componentes de serviço em um computador.  Componentes de serviço são componentes COM\+ que são executados em um sistema e podem ser usados por computadores na mesma rede.  Elas são gerenciadas pela funcionalidade de serviços de componentes no painel de controle do Windows.  
  
### Etapa 1.Convertendo o arquivo do projeto.  
 O arquivo de projeto converte facilmente e produz um relatório de migração.  Há algumas entradas no relatório que conte para nós sobre problemas que talvez seja necessário lidar com.  Este é um problema reportado \(Observe que ao longo deste tópico, mensagens de erro são às vezes reduzidas para facilitar a leitura, por exemplo, para remover os caminhos completos\):  
  
  **ComSpyAudit\\ComSpyAudit.vcproj: MSB8012: $ \(TargetPath\) \('C:\\Users\\UserName\\Desktop\\spy\\spy\\ComSpyAudit\\.  \\XP32\_DEBUG\\ComSpyAudit.dll'\) não coincide com o valor da propriedade do bibliotecário OutputFile '.  \\XP32\_DEBUG\\ComSpyAudit.dll' \('C:\\Users\\UserName\\Desktop\\spy\\spy\\XP32\_DEBUG\\ComSpyAudit.dll'\) na configuração do projeto ' Unicode Debug&#124; Win32'.  Isso pode causar o projeto para criar incorretamente.  Para corrigir isso, certifique\-se de que o valor da propriedade $ \(TargetPath\) corresponde ao valor especificado em % \(Lib.OutputFile\).**  Um dos problemas freqüentes em atualizar projetos é a configuração de arquivo de saída do vinculador na caixa de diálogo Propriedades do projeto talvez precise ser revisado.  O arquivo de saída é uma configuração que o Assistente de conversão automática tem problemas, se ele for definido como um valor não padrão para projetos antes do Visual Studio 2010.  Nesse caso, os caminhos para os arquivos de saída foram definidos em uma pasta padrão, XP32\_DEBUG.  Para saber mais sobre este erro, é consultado um [postagem de blog](http://blogs.msdn.com/b/vcblog/archive/2010/03/02/visual-studio-2010-c-project-upgrade-guide.aspx) relacionadas à atualização de projeto do Visual C\+\+ 2010, foi a atualização que envolveu a mudança de vcbuild para msbuild, uma alteração significativa.  De acordo com essas informações, o valor padrão para a configuração do arquivo de saída quando você cria um novo projeto é $\(OutDir\)$\(TargetName\)$\(TargetExt\), mas isso não é definida durante a conversão porque não é possível para projetos convertidos verificar se tudo está correto.  No entanto, vamos tente colocar isso em para o arquivo de saída e verificar se ele funciona.  Ele faz, portanto, podemos passar.  Se não houver nenhum motivo específico para usar uma pasta de saída padrão, é recomendável usar o local padrão.  Nesse caso, escolhemos deixar o local de saída que não padrão durante o processo de portabilidade e atualização; $ \(OutDir\) resolve para a pasta XP32\_DEBUG na configuração de depuração e a pasta ReleaseU para a configuração de versão.  
  
### Etapa 2.Fazer a compilação  
 Criando o projeto de portado, ocorre um número de erros e avisos.  
  
 ComSpyCtl não é compilada embora devido a esse erro do compilador:  
  
  **atlcom.h\(611\): erro C2664: 'CComSpy::IPersistStreamInit\_Save\(LPSTREAM,BOOL,ATL::ATL\_PROPMAP\_ENTRY \*\) HRESULT': não é possível converter o argumento 3 de ' const ATL::ATL\_PROPMAP\_ENTRY \*' para ' ATL::ATL\_PROPMAP\_ENTRY \*'**  
**atlcom.h\(611\): Observação: conversão perde qualificadores**  
**atlcom.h\(608\): Observação: ao compilar a função de membro de modelo de classe ' HRESULT ATL::IPersistStreamInitImpl \< CComSpy \>:: Save\(LPSTREAM,BOOL\)'**  
**\\spy\\spy\\comspyctl\\ccomspy.h\(28\): Observação: consulte a referência a instanciação do modelo de classe 'ATL::IPersistStreamInitImpl \< CComSpy \>' está sendo compilado** O erro referencia o método Save na classe IPersistStreamInitImpl atlcom.h.  
  
```  
STDMETHOD(Save)(_Inout_ LPSTREAM pStm, _In_ BOOL fClearDirty)  
{  
T* pT = static_cast<T*>(this);  
ATLTRACE(atlTraceCOM, 2, _T("IPersistStreamInitImpl::Save\n"));  
return pT->IPersistStreamInit_Save(pStm, fClearDirty, T::GetPropertyMap());  
}  
```  
  
 O problema é que uma conversão que aceita uma versão mais antiga do compilador não é mais válida.  Para estar de acordo com o padrão C\+\+, um código que anteriormente era permitido não é mais permitido.  Nesse caso, não é seguro passar um ponteiro não const para uma função que espera um ponteiro const.  A solução é encontrar a declaração de IPersistStreamInit\_Save na classe CComSpy e adicione o modificador const para o terceiro parâmetro.  
  
```  
HRESULT CComSpy::IPersistStreamInit_Save(LPSTREAM pStm, BOOL /* fClearDirty */, const ATL_PROPMAP_ENTRY* pMap)  
  
```  
  
 E uma alteração similar para IPersistStreamInit\_Load.  
  
```  
HRESULT IPersistStreamInit_Load(LPSTREAM pStm, const ATL_PROPMAP_ENTRY* pMap);  
```  
  
 O próximo erro lida com o registro.  
  
  **Erro MSB3073: O comando "regsvr32 \/s \/c"C:\\Users\\username\\Desktop\\spy\\spy\\ComSpyCtl\\.  \\XP32\_DEBUG\\ComSpyCtl.lib"**  
**Erro MSB3073: echo regsvr32 exec.  tempo \> ".  \\XP32\_DEBUG\\regsvr32.trg"**  
**Erro MSB3073:**  
**Erro MSB3073:: VCEnd "foi encerrado com o código 3.**  Não precisamos desse comando pós\-compilação registro mais.  Em vez disso, simplesmente remova o comando de compilação personalizada e especificar nas configurações do vinculador para registrar a saída.  
  
### Lidando com avisos  
 O projeto produz o vinculador seguinte aviso.  
  
  **Aviso LNK4075: ignorando ' \/ EDITANDCONTINUE' devido a ' \/ \/SafeSEH ' especificação** A opção de compilador \/SAFESEH não é útil no modo de depuração, que é quando \/EDITANDCONTINUE é útil para a correção aqui é desabilitar \/SAFESEH para apenas as configurações de depuração.  Para fazer isso na caixa de diálogo Propriedades, nós abrimos a caixa de diálogo Propriedades do projeto que gera esse erro e definimos primeiro a configuração de depuração \(na verdade, depurar Unicode\) e, em seguida, na seção avançada do vinculador, redefinir a propriedade de imagem tem manipuladores de exceção seguros como não \(\/ SAFESEH:NO\).  
  
 O compilador nos avisa que PROP\_ENTRY\_EX foi preterido.  Não é seguro e o substituto recomendado é PROP\_ENTRY\_TYPE\_EX.  
  
```  
BEGIN_PROPERTY_MAP(CComSpy)  
PROP_ENTRY_EX( "LogFile", DISPID_LOGFILE, CLSID_ComSpyPropPage, IID_IComSpy)  
PROP_ENTRY_EX( "ShowGridLines", DISPID_GRIDLINES, CLSID_ComSpyPropPage, IID_IComSpy)  
PROP_ENTRY_EX( "Audit", DISPID_AUDIT, CLSID_ComSpyPropPage, IID_IComSpy)  
PROP_ENTRY_EX( "ColWidth", DISPID_COLWIDTH, CLSID_ComSpyPropPage, IID_IComSpy)  
PROP_PAGE(CLSID_StockFontPage)  
END_PROPERTY_MAP()  
```  
  
 Podemos alterar o código ccomspy.h da mesma forma, adicionando tipos COM como apropriado.  
  
```  
BEGIN_PROPERTY_MAP(CComSpy)  
PROP_ENTRY_TYPE_EX( "LogFile", DISPID_LOGFILE, CLSID_ComSpyPropPage, IID_IComSpy, VT_BSTR)  
PROP_ENTRY_TYPE_EX( "ShowGridLines", DISPID_GRIDLINES, CLSID_ComSpyPropPage, IID_IComSpy, VT_BOOL)  
PROP_ENTRY_TYPE_EX( "Audit", DISPID_AUDIT, CLSID_ComSpyPropPage, IID_IComSpy, VT_BOOL)  
PROP_ENTRY_TYPE_EX( "ColWidth", DISPID_COLWIDTH, CLSID_ComSpyPropPage, IID_IComSpy, VT_UINT)  
PROP_PAGE(CLSID_StockFontPage)  
END_PROPERTY_MAP()  
```  
  
 Estamos obtendo para baixo até a última alguns avisos, que também são causados por verificações de compatibilidade mais restrito do compilador:  
  
  **\\spy\\comspyctl\\usersub.h\(70\): aviso C4457: declaração de 'var' oculta o parâmetro de função**  
**\\spy\\comspyctl\\usersub.h\(48\): Observação: consulte a declaração de 'var'**  
**\\spy\\comspyctl\\usersub.h\(94\): aviso C4018: ' \<': incompatibilidade assinada\/não**  
 **ComSpy.cpp**  
**\\spy\\comspyctl\\comspy.cpp\(186\): aviso C4457: declaração de 'bHandled' oculta o parâmetro de função**  
**\\spy\\spy\\comspyctl\\comspy.cpp\(177\): Observação: consulte a declaração de 'bHandled'** Aviso C4018 vem deste código:  
  
```  
for (i=0;i<lCount;i++)  
    CoTaskMemFree(pKeys[i]);  
```  
  
 O problema é que i é declarado como UINT e lCount é declarado como longa, portanto, a incompatibilidade assinada\/não assinada.  Seria inconveniente alterar o tipo de lCount para UINT, pois ele obtém seu valor de IMtsEventInfo::get\_Count, que usa o tipo de tempo e não no código do usuário.  Então, adicionamos uma conversão para o código.  Uma conversão do estilo C faria para uma conversão numérica como este, mas static\_cast é o estilo recomendado.  
  
```  
for (i=0;i<static_cast<UINT>(lCount);i++)  
    CoTaskMemFree(pKeys[i]);  
```  
  
 Esses avisos são casos em que uma variável foi declarada em uma função que tem um parâmetro com o mesmo nome, levando a potencialmente confusas código.  Corrigimos isso alterando os nomes das variáveis locais.  
  
```  
  
```  
  
### Etapa 3.Testando e depurando  
 Testamos o aplicativo pela primeira vez, em execução por meio de vários menus e comandos e fechando o aplicativo.  O único problema observado era uma asserção de depuração após fechar o aplicativo.  O problema apareceu no destruidor de CWindowImpl, uma classe base do objeto CSpyCon, o componente principal do aplicativo.  Falha de asserção ocorreu no código a seguir no atlwin.h.  
  
```  
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
  
 O hWnd normalmente é definido como zero na função WindowProc, mas isso não acontecer porque em vez do padrão WindowProc, um manipulador personalizado é chamado para a mensagem do Windows \(WM\_SYSCOMMAND\) que fecha a janela.  O manipulador personalizado não estava definindo o hWnd como zero.  Uma olhada no código semelhante na classe de CWnd do MFC, mostra que, quando uma janela for destruída, OnNcDestroy é chamado e no MFC, a documentação recomenda que ao substituir CWnd::OnNcDestroy, o NcDestroy base deve ser chamado para certificar\-se de que as operações de limpeza a direita ocorrerem, incluindo separando o identificador de janela da janela, ou em outras palavras, definindo o hWnd como zero.  Essa declaração pode foram acionada na versão original do exemplo, uma vez que o mesmo código de asserção estava presente na versão antiga do atlwin.h.  
  
 Para testar a funcionalidade do aplicativo, criamos um componente atendido usando o modelo de projeto ATL, decidiu adicionar suporte a COM\+ no ATL project wizard.  Se você não tiver trabalhado com componentes atendidos antes, não é difícil para criá\-lo e obter uma registrados e disponível no sistema ou na rede para outros aplicativos para usar.  O aplicativo COM Spy foi projetado para monitorar a atividade dos componentes de serviço como um auxílio de diagnóstico.  
  
 Em seguida, adicionamos uma classe, escolher objeto ATL e especificado o nome do objeto como Dog.  Em seguida, no dog.h e dog.cpp, adicionamos a implementação.  
  
```  
STDMETHODIMP CDog::Wag(LONG* lDuration)  
{  
    // TODO: Add your implementation code here  
    *lDuration = 100l;  
    return S_OK;  
}  
```  
  
 Em seguida, criamos e registrá\-lo \(você precisará executar o Visual Studio como administrador\) e ative\-o usando o aplicativo de componente atendido no painel de controle do Windows.  Criar um projeto c\# Windows Forms, arrastado um botão ao formulário da caixa de ferramentas e clicado duas vezes que a um manipulador de eventos.  Adicionamos o seguinte código para instanciar o componente Dog.  
  
```  
private void button1_Click(object sender, EventArgs e)  
{  
    ATLProjectLib.Dog dog1 = new ATLProjectLib.Dog();  
    dog1.Wag();  
}  
```  
  
 Isso foi executado sem problemas e com Spy COM backup e em execução e configurado para monitorar o componente Dog, grandes quantidades de dados aparece, indicando que a atividade.  
  
## Consulte também  
 [Portando e atualizando: exemplos e estudos de caso](../porting/porting-and-upgrading-examples-and-case-studies.md)   
 [próximo exemplo: Spy \+ \+](../Topic/Porting%20Guide:%20Spy++.md)   
 [exemplo anterior: Rabisco MFC](../porting/porting-guide-mfc-scribble.md)