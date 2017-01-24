---
title: "DLLs de extens&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "afxdll"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Biblioteca AFXDLL"
  - "DLLs [C++], extensão"
  - "DLLs de extensão [C++]"
  - "DLLs de extensão [C++], sobre DLLs de extensão"
  - "memória [C++], DLLs"
  - "DLLs MFC [C++], DLLs de extensão"
  - "extensão de MFC [C++]"
  - "compartilhamento de recursos [C++]"
  - "versões de DLLs compartilhadas [C++]"
  - "recursos compartilhados [C++]"
ms.assetid: f69ac3d4-e474-4b1c-87a1-6738843a135c
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# DLLs de extens&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma DLL da extensão MFC é uma DLL que implementa normalmente reutilizáveis as classes derivadas das classes existentes da biblioteca de classes do Microsoft.  
  
 Uma DLL da extensão MFC tem os seguintes recursos e requisitos:  
  
-   O cliente que o executável deve ser um aplicativo MFC compilado com **\_AFXDLL** definiu.  
  
-   Uma DLL da extensão também pode ser usado por uma DLL normal vinculada dinamicamente ao MFC.  
  
-   Dlls de extensão deve ser compilado com `_AFXEXT` definidas.  Isso força **\_AFXDLL** a ser definido e também assegura que as instruções apropriadas sejam recebidas nos arquivos de cabeçalho MFC.  Também garante que **AFX\_EXT\_CLASS** está definido como **\_\_declspec\(dllexport\)** ao criar a DLL, que será necessário se você estiver usando esta macro para declarar as classes em seu DLL da extensão.  
  
-   Dlls de extensão não devem criar uma instância de uma classe derivada de `CWinApp`, mas devem confiar no aplicativo cliente \(ou na DLL\) fornecer esse objeto.  
  
-   Dlls de extensão deve, no entanto, forneça uma função de `DllMain` e fazer qualquer inicialização necessárias para ela.  
  
 Dlls de extensão são criados usando a versão da biblioteca de vínculo dinâmico\) nativa MFC \(também conhecido como a versão compartilhada MFC\).  Somente os executáveis \(MFC aplicativos ou DLL normais\) que é criado com uma versão compartilhada MFC podem usar uma DLL da extensão.  O aplicativo cliente e a DLL de extensão devem usar a mesma versão de MFCx0.dll.  Com uma DLL da extensão, você pode derivar novas classes personalizadas MFC e depois oferecer essa versão estendida de MFC para aplicativos que chamam o DLL.  
  
 Dlls de extensão também podem ser usados passando objetos MFC\- derivadas entre o aplicativo e a DLL.  As funções de membro associadas ao objeto passado existem no módulo em que o objeto foi criado.  Como essas funções são exportadas corretamente ao usar a versão compartilhada MFC da DLL, você pode transmitir livremente MFC o ou ponteiros MFC\- derivados do objeto entre um aplicativo e as dlls de extensão que carregou.  
  
 Uma DLL da extensão MFC usa uma versão compartilhada MFC da mesma forma que um aplicativo usa a versão compartilhada da DLL MFC, com algumas considerações adicionais:  
  
-   Não tem `CWinApp`\- objeto derivada.  Deve trabalhar com `CWinApp`\- objeto derivado do aplicativo cliente.  Isso significa que o aplicativo cliente possui a bomba principal da mensagem, o loop ociosa, e assim por diante.  
  
-   Chama `AfxInitExtensionModule` na função de `DllMain` .  O valor de retorno dessa função deve ser verificado.  Se um valor nulo será retornado de `AfxInitExtensionModule`, retorna 0 da função de `DllMain` .  
  
-   Cria um objeto de **CDynLinkLibrary** durante a inicialização se a DLL de extensão deseja exportar objetos ou recursos de `CRuntimeClass` ao aplicativo.  
  
 Antes da versão 4,0 MFC, esse tipo de DLL foi chamado em um AFXDLL.  AFXDLL se refere ao símbolo de pré\-processador de **\_AFXDLL** que é definido durante a criação da DLL.  
  
 As bibliotecas de importação para a versão compartilhada MFC são nomeadas de acordo com a convenção descrita em [Convenções de nomenclatura para dlls MFC](../build/naming-conventions-for-mfc-dlls.md).  Visual C\+\+ fornece versões de prebuilt de DLL MFC, mais um número de DLL não MFC que você pode usar e distribuir com seus aplicativos.  Esses são documentados em Redist.txt, que é instalado na pasta arquivos de programas \\ Microsoft Visual Studio.  
  
 Se você estiver exportando usando um arquivo .def, coloque o código a seguir no início e o término do arquivo de cabeçalho:  
  
```  
#undef AFX_DATA  
#define AFX_DATA AFX_EXT_DATA  
// <body of your header file>  
#undef AFX_DATA  
#define AFX_DATA  
```  
  
 Essas quatro linhas garantem que o código seja criado corretamente para uma DLL da extensão.  Omitir essas quatro linhas pode causar o DLL para criar ou links incorretamente.  
  
 Se você precisa passar um MFC ou um ponteiro MFC\- derivado do objeto para ou de uma DLL MFC, a DLL deve ser uma DLL da extensão.  As funções de membro associadas ao objeto passado existem no módulo em que o objeto foi criado.  Como essas funções são exportadas corretamente ao usar a versão compartilhada MFC da DLL, você pode transmitir livremente MFC o ou ponteiros MFC\- derivados do objeto entre um aplicativo e as dlls de extensão que carregou.  
  
 Devido a problemas de massacre e exportação do nome do C\+\+, a lista de exportação de uma DLL de extensão pode ser diferente entre a depuração e as versões de varejo do mesmo DLL e DLL para plataformas diferentes.  O varejo MFCx0.dll tem cerca de 2.000 pontos de entrada exportados; a depuração MFCx0D.dll tem cerca de 3.000 pontos de entrada exportados.  
  
## Gerenciamento de memória  
 MFCx0.dll e todas as dlls de extensão carregados no espaço de endereço de um aplicativo cliente usam o mesmo alocador de memória, a carga de recursos, e outros estados globais MFC como se estivesse no mesmo aplicativo.  Isso é significativo como as bibliotecas da DLL NÃO\- MFC e as dlls normais fazem o oposto exato e têm a cada DLL que atribui fora de seu próprio pool de memória.  
  
 Se uma DLL da extensão aloca memória, essa memória pode misturar\-se livremente com qualquer outro objeto atribuído pelo aplicativo.  Além disso, se um aplicativo que vincula dinamicamente MFC ao falhar, a proteção do sistema operacional mantém a integridade de qualquer outro aplicativo MFC que compartilha a DLL.  
  
 De maneira semelhante outros estados globais MFC, como o arquivo executável atual para carregar recursos do, também são compartilhados entre o aplicativo cliente e todas as dlls de extensão MFC bem como MFCx0.dll próprio.  
  
## Compartilhando recursos e classes  
 Exportar recursos é feito por meio de uma lista de recursos.  Cada aplicativo lista contém uma única vinculada de objetos de **CDynLinkLibrary** .  Ao procurar um recurso, a maioria das implementações de MFC padrão que carregam recursos e verifique primeiro no módulo atual de recursos \(\) e`AfxGetResourceHandle`se o recurso não for encontrada exames a lista de objetos **CDynLinkLibrary** a tentativa de carregar o recurso solicitado.  
  
 Percorrer a lista tem as desvantagens que é ligeiramente mais lento e requer gerenciar intervalos de ID de recurso.  Tem a vantagem de um aplicativo cliente que vincula a vários DLL de extensão pode usar qualquer DLL\- forneceu o recurso sem ter que especifique o identificador de instância da DLL.  é usado`AfxFindResourceHandle` API examinando a lista de recursos para procurar uma correspondência determinada.  Tem o nome e o tipo de um recurso e retorna o identificador de recurso em que foi encontrada pela primeira vez \(ou NULL\).  
  
 Se você não quiser percorrer a lista e somente os recursos de carregamento de um local específico, use as funções `AfxGetResourceHandle` e `AfxSetResourceHandle` para salvar o identificador antigo e para definir a novo identificador.  Restaure todo o identificador antigo de recursos antes que você retorna ao aplicativo cliente.  Para obter um exemplo de como usar esta abordagem para carregar explicitamente um menu, consulte Testdll2 .cpp no exemplo [DLLHUSK](http://msdn.microsoft.com/pt-br/dfcaa6ff-b8e2-4efd-8100-ee3650071f90)MFC.  
  
 A criação de objetos dinâmico MFC dados um nome de MFC é semelhante.  O mecanismo de desserialização do objeto de MFC precisa ter todos os objetos de `CRuntimeClass` registrados de modo que possa recriar dinamicamente criando objetos do C\+\+ de tipo necessário com base no que foi anteriormente armazenado.  
  
 No caso de exemplo [DLLHUSK](http://msdn.microsoft.com/pt-br/dfcaa6ff-b8e2-4efd-8100-ee3650071f90)MFC, a lista examina algo como:  
  
```  
head ->   DLLHUSK.EXE   - or -   DLLHUSK.EXE  
               |                      |  
          TESTDLL2.DLL           TESTDLL2.DLL  
               |                      |  
          TESTDLL1.DLL           TESTDLL1.DLL  
               |                      |  
           MFCOxxD.DLL                |  
               |                      |  
           MFCDxxD.DLL                |  
               |                      |  
            MFCxxD.DLL            MFCxx.DLL  
```  
  
 onde *xx* é o número de versão; por exemplo, 42 representam a versão 4,2.  
  
 O MFCxx.dll é geralmente o mais recente na lista de recursos e da classe.  MFCxx.dll inclui todos os recursos de MFC padrão, incluindo cadeias de caracteres alertas para todas as IDs padrão do comando.  Colocá\-lo no final da lista permite que a DLL e o aplicativo cliente em si não ter sua própria cópia dos recursos de MFC padrão, mas em vez de confiar em recursos compartilhados no MFCxx.dll.  
  
 Mesclar os recursos e os nomes da classe de todas as dlls no espaço de nome de aplicativo cliente tem a desvantagem de exigir que você ter cuidado com que as IDs ou nomes de sua escolha.  
  
 O exemplo de [DLLHUSK](http://msdn.microsoft.com/pt-br/dfcaa6ff-b8e2-4efd-8100-ee3650071f90) gerencia o espaço de nome compartilhado de recursos usando vários arquivos de cabeçalho.  
  
 Se seu DLL de extensão MFC deve manter dados adicionais para cada aplicativo, você pode derivar uma nova classe de **CDynLinkLibrary** e criá\-la em `DllMain`.  Ao executar, a DLL pode verificar a lista atual do aplicativo de objetos de **CDynLinkLibrary** para localizar o para que o DLL específico de extensão.  
  
### O que você deseja fazer?  
  
-   [Inicializar uma DLL da extensão](../build/initializing-extension-dlls.md)  
  
### Que você deseja saber mais?  
  
-   [Dicas sobre como usar arquivos de recursos compartilhados](../mfc/tn035-using-multiple-resource-files-and-header-files-with-visual-cpp.md)  
  
-   [Versão de DLL do MFC](../mfc/tn033-dll-version-of-mfc.md)  
  
-   [DLL normais vinculadas estaticamente ao MFC](../build/regular-dlls-statically-linked-to-mfc.md)  
  
-   [DLL normais vinculadas dinamicamente ao MFC](../Topic/Regular%20DLLs%20Dynamically%20Linked%20to%20MFC.md)  
  
-   [Usando o base de dados, o OLE, e as dlls de extensão de soquetes na DLL normais](../build/using-database-ole-and-sockets-extension-dlls-in-regular-dlls.md)  
  
## Consulte também  
 [DLLs no Visual C\+\+](../build/dlls-in-visual-cpp.md)