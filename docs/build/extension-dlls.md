---
title: DLLs de extensão | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
f1_keywords:
- afxdll
dev_langs:
- C++
helpviewer_keywords:
- memory [C++], DLLs
- MFC extension DLLs [C++]
- AFXDLL library
- shared resources [C++]
- MFC DLLs [C++], MFC extension DLLs
- DLLs [C++], extension
- shared DLL versions [C++]
- resource sharing [C++]
- extension DLLs [C++]
- extension DLLs [C++], about MFC extension DLLs
ms.assetid: f69ac3d4-e474-4b1c-87a1-6738843a135c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6f60540735be44adf4305dcda77373faf8a83514
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="mfc-extension-dlls"></a>DLLs de extensão do MFC
Uma extensão do MFC DLL é uma DLL que implementa normalmente reutilizáveis classes derivadas de classes existentes de biblioteca Microsoft Foundation Class.  
  
 Uma DLL de extensão do MFC tem os seguintes recursos e requisitos:  
  
-   O executável do cliente deve ser um aplicativo MFC compilado com `_AFXDLL` definido.  
  
-   Uma DLL de extensão do MFC também pode ser usado por uma DLL MFC regular vinculada dinamicamente a MFC.  
  
-   DLLs de extensão do MFC devem ser compilada com `_AFXEXT` definido. Isso força `_AFXDLL` também seja definido e garante que as declarações adequadas é retirada dos arquivos de cabeçalho do MFC. Ela também garante que `AFX_EXT_CLASS` é definido como `__declspec(dllexport)` ao criar a DLL, que é necessário se você estiver usando essa macro para declarar as classes em sua DLL de extensão do MFC.  
  
-   DLLs de extensão do MFC não devem instanciar uma classe derivada de `CWinApp`, mas deve confiar no aplicativo cliente (ou DLL) para fornecer esse objeto.  
  
-   DLLs de extensão do MFC devem, no entanto, fornecer um `DllMain` de função e fazer qualquer inicialização necessária existe.  
  
 DLLs de extensão são criados usando a versão da biblioteca de vínculo dinâmico do MFC (também conhecido como a versão compartilhada do MFC). Somente MFC executáveis (aplicativos ou a DLLs normais do MFC) que são criados com a versão compartilhada do MFC podem usar uma DLL de extensão do MFC. O aplicativo cliente e a DLL de extensão do MFC devem usar a mesma versão do MFCx0.dll. Com uma extensão MFC DLL, você pode derivar novas classes personalizadas de MFC e, em seguida, oferecer essa versão estendida do MFC para aplicativos que chamam a DLL.  
  
 DLLs de extensão também podem ser usados para transmitir objetos derivados de MFC entre o aplicativo e a DLL. As funções de membro associadas ao objeto passado existem no módulo onde o objeto foi criado. Como essas funções são exportadas corretamente ao usar a versão DLL compartilhada do MFC, você pode passar livremente MFC ou ponteiros para objetos derivados MFC entre um aplicativo e a extensão MFC DLLs, ele carrega.  
  
 Uma DLL de extensão do MFC usa uma versão compartilhada do MFC da mesma forma que um aplicativo usa a versão DLL compartilhada do MFC, com algumas considerações adicionais:  
  
-   Ele não tem um `CWinApp`-objeto derivado. Ele deve funcionar com o `CWinApp`-derivados do objeto do aplicativo cliente. Isso significa que o aplicativo cliente possui a bomba de mensagem principal, o loop ocioso e assim por diante.  
  
-   Ele chama `AfxInitExtensionModule` no seu `DllMain` função. O valor de retorno dessa função deve ser verificado. Se um valor zero é retornado de `AfxInitExtensionModule`, retornam 0 do seu `DllMain` função.  
  
-   Ele cria um **CDynLinkLibrary** durante a inicialização do objeto se a extensão MFC DLL deseja exportar `CRuntimeClass` objetos ou recursos para o aplicativo.  
  
 Antes da versão 4.0 do MFC, esse tipo de DLL foi chamado um AFXDLL. AFXDLL refere-se para o `_AFXDLL` símbolo do pré-processador que é definido durante a criação da DLL.  
  
 As bibliotecas de importação para a versão compartilhada do MFC são nomeadas de acordo com a convenção descrita no [convenções de nomenclatura para DLLs MFC](../mfc/mfc-library-versions.md#mfc-static-library-naming-conventions). Visual C++ fornece versões pré-compilada as MFC DLLs, além de um número de DLLs não MFC que você pode usar e distribuir aos seus aplicativos. Essas situações são documentadas Redist, que é instalado na pasta Program Files\Microsoft Visual Studio.  
  
 Se você estiver exportando usando um arquivo. def, coloque o seguinte código no início e no final do arquivo de cabeçalho:  
  
```cpp  
#undef AFX_DATA  
#define AFX_DATA AFX_EXT_DATA  
// <body of your header file>  
#undef AFX_DATA  
#define AFX_DATA  
```  
  
 Estas quatro linhas Certifique-se de que seu código é compilado corretamente para uma DLL de extensão do MFC. Omitindo estas quatro linhas pode causar a DLL compilar ou vincular incorretamente.  
  
 Se você precisar passar um MFC ou ponteiro de objeto derivado de MFC ou para uma DLL MFC, a DLL deve ser uma DLL de extensão do MFC. As funções de membro associadas ao objeto passado existem no módulo onde o objeto foi criado. Como essas funções são exportadas corretamente ao usar a versão DLL compartilhada do MFC, você pode passar livremente MFC ou ponteiros para objetos derivados MFC entre um aplicativo e a extensão MFC DLLs, ele carrega.  
  
 Devido a nome desconfiguração e exportação problemas C++, a lista de exportação de uma extensão MFC DLL pode ser diferente entre as versões de depuração e de varejo da mesma DLL e DLLs para diferentes plataformas. Varejo MFCx0.dll sobre 2.000 exportou pontos de entrada; a depuração MFCx0D.dll tem aproximadamente 3.000 pontos de entrada exportado.  
  
## <a name="memory-management"></a>Gerenciamento de memória  
 MFCx0.dll e todas as DLLs carregadas no espaço de endereço de um aplicativo cliente de extensão do MFC usam o mesmo alocador de memória, carregamento de recursos e outros estados MFC globais como se estivessem no mesmo aplicativo. Isso é significativo porque as bibliotecas de DLL não - MFC DLLs normais do MFC fazer o oposto exato e ter cada DLL alocando fora de seu próprio pool de memória.  
  
 Se uma DLL de extensão do MFC aloca memória, que a memória pode combinar livremente com qualquer outro objeto alocado pelo aplicativo. Além disso, se um aplicativo que vincula dinamicamente a MFC falhar, a proteção do sistema operacional mantém a integridade de qualquer outro aplicativo do MFC a DLL de compartilhamento.  
  
 Da mesma forma outros estados MFC globais, como o arquivo executável atual ao carregar recursos, também são compartilhados entre o aplicativo cliente e todas as DLLs de extensão do MFC, bem como MFCx0.dll em si.  
  
## <a name="sharing-resources-and-classes"></a>Compartilhamento de recursos e Classes  
 Exportação de recursos é feita por meio de uma lista de recursos. Cada aplicativo contém uma lista individualmente vinculada de **CDynLinkLibrary** objetos. Ao procurar por um recurso, a maioria das implementações do MFC padrão que carregar recursos procuram primeira no módulo de recurso atual (`AfxGetResourceHandle`) e se o recurso não foi encontrado orientam a lista de **CDynLinkLibrary** objetos tentativa de carregar o recurso solicitado.  
  
 Percorra a lista tem as desvantagens que é um pouco mais lenta e requer o gerenciamento de intervalos de ID de recurso. Ele tem a vantagem de que um aplicativo cliente que contém links para várias DLLs de extensão do MFC pode usar qualquer recurso fornecido DLL sem ter que especificar o identificador de instância DLL. `AfxFindResourceHandle` uma API é usada para percorrer a lista de recursos para procurar uma correspondência determinada. Ele usa o nome e um tipo de recurso e retorna o identificador de recurso em que ele foi encontrado primeiro (ou nulo).  
  
 Se você não quiser percorrer a lista e carregar somente os recursos de um local específico, use as funções `AfxGetResourceHandle` e `AfxSetResourceHandle` para salvar o identificador antigo e definir o novo identificador. Certifique-se de restaurar o identificador de recurso antigo antes de retornar ao aplicativo cliente. Para obter um exemplo de como usar essa abordagem para carregar explicitamente um menu, consulte cpp Testdll2 no exemplo do MFC [DLLHUSK](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/MFC/advanced/dllhusk).  
  
 Criação dinâmica de objetos MFC recebe um nome MFC é semelhante. O mecanismo de desserialização de objetos MFC precisa ter todos os `CRuntimeClass` objetos registrados para que ele pode reconstruir criando dinamicamente objetos C++ do tipo necessário com base no que foi armazenado anteriormente.  
  
 No caso do exemplo MFC [DLLHUSK](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/MFC/advanced/dllhusk), a lista tem a seguinte aparência:  
  
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
  
 onde *xx* é o número de versão; por exemplo, 42 representa versão 4.2.  
  
 O MFCxx.dll é geralmente último na lista de classes e recursos. MFCxx.dll inclui todos os recursos padrão do MFC, inclusive cadeias de caracteres de prompt para todas as IDs de comando padrão. Permite que colocá-lo no final da lista de DLLs e o aplicativo de cliente em si não têm sua própria cópia dos recursos MFC padrão, mas a confiar nos recursos compartilhados no MFCxx.dll em vez disso.  
  
 Mesclando os recursos e os nomes de classe de todas as DLLs espaço para nome do aplicativo cliente tem a desvantagem de exigir que você tenha cuidado com a qual IDs ou nomes que você escolher.  
  
 O [DLLHUSK](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/MFC/advanced/dllhusk) exemplo gerencia o espaço de nome de recurso compartilhado usando vários arquivos de cabeçalho.  
  
 Se a DLL de extensão do MFC precisa manter dados extras para cada aplicativo, você pode derivar uma nova classe de **CDynLinkLibrary** e criá-lo em `DllMain`. Quando em execução, a DLL pode verificar a lista do aplicativo atual de **CDynLinkLibrary** objetos para localizar o item para essa extensão MFC DLL específico.  
  
### <a name="what-do-you-want-to-do"></a>O que você deseja fazer?  
  
-   [Inicializar uma DLL de extensão do MFC](../build/run-time-library-behavior.md#initializing-extension-dlls)  
  
### <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
  
-   [Dicas sobre como usar arquivos de recurso compartilhado](../mfc/tn035-using-multiple-resource-files-and-header-files-with-visual-cpp.md)  
  
-   [Versão de DLL do MFC](../mfc/tn033-dll-version-of-mfc.md)  
  
-   [DLLs normais do MFC vinculado estaticamente ao MFC](../build/regular-dlls-statically-linked-to-mfc.md)  
  
-   [DLLs MFC regulares vinculadas dinamicamente a MFC](../build/regular-dlls-dynamically-linked-to-mfc.md)  
  
-   [Usando banco de dados, OLE e DLLs de extensão de MFC de soquetes em DLLs MFC regulares](../build/using-database-ole-and-sockets-extension-dlls-in-regular-dlls.md)  
  
## <a name="see-also"></a>Consulte também  
 [DLLs no Visual C++](../build/dlls-in-visual-cpp.md)