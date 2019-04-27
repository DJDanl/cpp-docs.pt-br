---
title: DLLs de extensão
ms.date: 11/04/2016
f1_keywords:
- afxdll
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
ms.openlocfilehash: eca33b60b8fa6ba812bf5fa68520f51ceb1d164b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62195654"
---
# <a name="mfc-extension-dlls"></a>DLLs de extensão do MFC

Uma extensão MFC DLL é uma DLL que normalmente implementa classes reutilizáveis derivadas das classes existentes da biblioteca Microsoft Foundation Class.

Uma DLL de extensão do MFC tem os seguintes requisitos:

- O executável do cliente deve ser compilado com um aplicativo do MFC `_AFXDLL` definido.

- Uma DLL de extensão do MFC também pode ser usado por uma DLL MFC regular vinculada dinamicamente ao MFC.

- DLLs de extensão MFC devem ser compilada com `_AFXEXT` definido. Isso força `_AFXDLL` também seja definido e garante que as declarações apropriadas é retirada do arquivos de cabeçalho MFC. Ela também garante que `AFX_EXT_CLASS` é definido como `__declspec(dllexport)` ao criar a DLL, que é necessário se você estiver usando essa macro para declarar as classes em sua extensão MFC DLL.

- DLLs de extensão do MFC não devem instanciar uma classe derivada de `CWinApp`, mas deve depender do aplicativo cliente (ou DLL) para fornecer esse objeto.

- DLLs de extensão MFC devem, no entanto, fornecer um `DllMain` de função e fazer qualquer inicialização necessária existe.

DLLs de extensão são criados usando a versão da biblioteca de vínculo dinâmico do MFC (também conhecido como a versão compartilhada do MFC). Somente executáveis MFC (aplicativos ou DLLs MFC regulares) que são criados com a versão compartilhada do MFC podem usar uma DLL de extensão do MFC. O aplicativo cliente e a DLL de extensão do MFC devem usar a mesma versão do MFCx0.dll. Com uma DLL de extensão MFC, você pode derivar novas classes personalizadas de MFC e, em seguida, esta versão estendida do MFC para aplicativos que chamam a DLL da oferta.

DLLs de extensão também podem ser usadas para passar objetos derivados do MFC entre o aplicativo e a DLL. As funções de membro associadas com o objeto passado existem no módulo no qual o objeto foi criado. Porque essas funções são exportadas corretamente ao usar a versão DLL compartilhada do MFC, você pode passar livremente MFC ou ponteiros para objetos derivados do MFC entre um aplicativo e a extensão MFC DLLs, ele carrega.

Uma DLL de extensão do MFC usa uma versão compartilhada do MFC da mesma forma que um aplicativo usa a versão DLL compartilhada do MFC, com algumas considerações adicionais:

- Ele não tem um `CWinApp`-objeto derivado. Ele deve funcionar com o `CWinApp`-objeto do aplicativo cliente derivado. Isso significa que o aplicativo cliente que detém a bomba de mensagem principal, o loop ocioso e assim por diante.

- Ele chama `AfxInitExtensionModule` em seu `DllMain` função. O valor de retorno dessa função deve ser verificado. Se um valor de zero for retornado por `AfxInitExtensionModule`, retornam 0 de seu `DllMain` função.

- Ele cria uma **CDynLinkLibrary** durante a inicialização do objeto se a extensão MFC DLL deseja exportar `CRuntimeClass` objetos ou recursos para o aplicativo.

Antes da versão 4.0 do MFC, esse tipo de DLL foi chamado um AFXDLL. AFXDLL refere-se ao `_AFXDLL` símbolo do pré-processador que é definido ao criar a DLL.

As bibliotecas de importação para a versão compartilhada do MFC são nomeadas de acordo com a convenção descrita em [convenções de nomenclatura para DLLs MFC](../mfc/mfc-library-versions.md#mfc-static-library-naming-conventions). Visual C++ fornece versões predefinidas de DLLs do MFC, além de um número de DLLs não MFC que você pode usar e distribuir com seus aplicativos. Essas situações são documentadas em Redist, que é instalado na pasta Program Files\Microsoft Visual Studio.

Se você estiver exportando usando um arquivo. def, coloque o seguinte código no início e no final do seu arquivo de cabeçalho:

```cpp
#undef AFX_DATA
#define AFX_DATA AFX_EXT_DATA
// <body of your header file>
#undef AFX_DATA
#define AFX_DATA
```

Estas quatro linhas Certifique-se de que seu código seja compilado corretamente para uma DLL de extensão do MFC. Deixar essas quatro linhas pode fazer com que sua DLL compile ou vincule incorretamente.

Se você precisar passar um MFC ou ponteiro de objeto derivado de MFC para ou de uma DLL do MFC, a DLL deve ser uma DLL de extensão do MFC. As funções de membro associadas com o objeto passado existem no módulo no qual o objeto foi criado. Porque essas funções são exportadas corretamente ao usar a versão DLL compartilhada do MFC, você pode passar livremente MFC ou ponteiros para objetos derivados do MFC entre um aplicativo e a extensão MFC DLLs, ele carrega.

Devido a nome exportação e a desconfiguração de problemas de C++, a lista de exportação de uma extensão MFC DLL pode ser diferente entre versões de depuração e de varejo da mesma DLL e DLLs para diferentes plataformas. A edição de varejo MFCx0.dll tem cerca de 2.000 exportado pontos de entrada; a depuração MFCx0D.dll tem cerca de 3.000 pontos de entrada exportado.

## <a name="memory-management"></a>Gerenciamento de memória

MFCx0.dll e todas as DLLs carregadas no espaço de endereço de um aplicativo cliente de extensão do MFC usam o mesmo alocador de memória, carregamento de recursos e outros estados globais do MFC como se estivessem no mesmo aplicativo. Isso é significativo porque as bibliotecas de DLL não MFC e as DLLs MFC regulares não o oposto exato e tem cada DLL alocando fora de seu próprio pool de memória.

Se uma DLL de extensão do MFC aloca memória, que a memória pode combinar livremente com qualquer outro objeto alocado pelo aplicativo. Além disso, se um aplicativo que vincula dinamicamente ao MFC falhar, a proteção do sistema operacional mantém a integridade de qualquer outro aplicativo do MFC a DLL de compartilhamento.

Da mesma forma outros estados MFC globais, como o atual arquivo executável para carregar recursos, também são compartilhados entre o aplicativo cliente e todas as DLLs de extensão do MFC, bem como MFCx0.dll em si.

## <a name="sharing-resources-and-classes"></a>Compartilhamento de recursos e Classes

Exportando recursos é feito por meio de uma lista de recursos. Cada aplicativo contém uma lista individualmente vinculada de **CDynLinkLibrary** objetos. Quando você está procurando um recurso, a maioria das implementações padrão do MFC que carregar recursos ver primeira módulo de recursos atual (`AfxGetResourceHandle`) e se o recurso não for encontrado percorrer a lista de **CDynLinkLibrary** objetos tentativa de carregar o recurso solicitado.

Percorrer a lista tem as desvantagens que ele é um pouco mais lento e requer o gerenciamento de intervalos de ID de recurso. Ele tem a vantagem de que um aplicativo cliente que contém links para várias DLLs de extensão MFC pode usar qualquer recurso fornecido pelo DLL sem ter que especificar o identificador de instância DLL. `AfxFindResourceHandle` é uma API usada para percorrer a lista de recursos para procurar uma correspondência de determinado. Ele usa o nome e um tipo de recurso e retorna o identificador de recurso em que foi encontrada pela primeira vez (ou nulo).

Se você não deseja percorrer a lista e carregar somente os recursos de um local específico, use as funções `AfxGetResourceHandle` e `AfxSetResourceHandle` para salvar o antigo identificador e definir o novo identificador. Certifique-se de restaurar o antigo identificador do recurso antes de retornar para o aplicativo cliente. Para obter um exemplo de como usar essa abordagem para carregar explicitamente um menu, consulte. cpp do Testdll2 no exemplo de MFC [DLLHUSK](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/MFC/advanced/dllhusk).

Criação dinâmica de objetos MFC recebe um nome de MFC é semelhante. O mecanismo de desserialização do objeto MFC precisa ter todos os `CRuntimeClass` objetos registrados para que ele pode reconstruir ao criar dinamicamente objetos de C++ do tipo necessário com base no que foi armazenado anteriormente.

No caso do exemplo MFC [DLLHUSK](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/MFC/advanced/dllhusk), a lista se parece com:

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

em que *xx* é o número de versão; por exemplo, 42 representa a versão 4.2.

O compartilhadas é geralmente último na lista de classes e recursos. Compartilhadas inclui todos os recursos padrão do MFC, incluindo cadeias de caracteres de prompt para todas as IDs de comando padrão. Permite que colocá-lo no final da lista de DLLs e o aplicativo de cliente em si não têm sua própria cópia do padrão de recursos do MFC, mas contar com os recursos compartilhados no compartilhadas em vez disso.

Mesclando os recursos e nomes de classe de todas as DLLs de espaço para nome do aplicativo cliente tem a desvantagem de exigir que você tenha cuidado com os quais IDs ou nomes que você escolher.

O [DLLHUSK](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/MFC/advanced/dllhusk) exemplo gerencia o espaço de nome de recurso compartilhado por meio de vários arquivos de cabeçalho.

Se sua extensão MFC DLL precisa manter os dados extras para cada aplicativo, você pode derivar uma nova classe de **CDynLinkLibrary** e crie-a em `DllMain`. Quando em execução, a DLL pode verificar a lista do aplicativo atual de **CDynLinkLibrary** objetos para localizar o item para essa extensão MFC DLL específico.

### <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Inicializar uma DLL de extensão do MFC](run-time-library-behavior.md#initializing-extension-dlls)

### <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [Dicas sobre como usar arquivos de recurso compartilhado](../mfc/tn035-using-multiple-resource-files-and-header-files-with-visual-cpp.md)

- [Versão DLL do MFC](../mfc/tn033-dll-version-of-mfc.md)

- [DLLs MFC regulares vinculadas estaticamente ao MFC](regular-dlls-statically-linked-to-mfc.md)

- [DLLs MFC regulares vinculadas dinamicamente ao MFC](regular-dlls-dynamically-linked-to-mfc.md)

- [Usando banco de dados, OLE e DLLs de extensão de MFC de soquetes em DLLs MFC regulares](using-database-ole-and-sockets-extension-dlls-in-regular-dlls.md)

## <a name="see-also"></a>Consulte também

[DLLs no Visual C++](dlls-in-visual-cpp.md)
