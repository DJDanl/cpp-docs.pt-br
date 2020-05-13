---
title: DLLs de extensão
ms.date: 05/06/2019
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
ms.openlocfilehash: 55b1e55a9c7bdf6daaff98a7fe3f1a2a55f68334
ms.sourcegitcommit: da32511dd5baebe27451c0458a95f345144bd439
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2019
ms.locfileid: "65220768"
---
# <a name="mfc-extension-dlls"></a>DLLs de extensão de MFC

Uma DLL de extensão do MFC é uma DLL que normalmente implementa classes reutilizáveis derivadas das classes de biblioteca MFC existentes.

Uma DLL de extensão do MFC tem os seguintes recursos e requisitos:

- O executável do cliente deve ser um aplicativo MFC compilado `_AFXDLL` com o definido.

- Uma DLL de extensão do MFC também pode ser usada por uma DLL do MFC regular que é vinculada dinamicamente ao MFC.

- As DLLs de extensão do MFC devem `_AFXEXT` ser compiladas com o definido. Essa força `_AFXDLL` também deve ser definida e garante que as declarações apropriadas sejam extraídas dos arquivos de cabeçalho do MFC. Ele também garante que `AFX_EXT_CLASS` é definido como `__declspec(dllexport)` durante a criação da dll, o que é necessário se você estiver usando essa macro para declarar as classes em sua DLL de extensão do MFC.

- As DLLs de extensão do MFC não devem instanciar `CWinApp`uma classe derivada de, mas devem depender do aplicativo cliente (ou dll) para fornecer esse objeto.

- No entanto, as DLLs de extensão do `DllMain` MFC devem fornecer uma função e fazer qualquer inicialização necessária ali.

As DLLs de extensão são criadas usando a versão da biblioteca de vínculo dinâmico do MFC (também conhecida como a versão compartilhada do MFC). Somente os executáveis do MFC (aplicativos ou DLLs regulares do MFC) criados com a versão compartilhada do MFC podem usar uma DLL de extensão do MFC. O aplicativo cliente e a DLL de extensão do MFC devem usar a mesma versão de MFCx0. dll. Com uma DLL de extensão do MFC, você pode derivar novas classes personalizadas do MFC e, em seguida, oferecer essa versão estendida do MFC a aplicativos que chamam sua DLL.

DLLs de extensão também podem ser usadas para passar objetos derivados do MFC entre o aplicativo e a DLL. As funções de membro associadas ao objeto passado existem no módulo em que o objeto foi criado. Como essas funções são exportadas corretamente ao usar a versão de DLL compartilhada do MFC, você pode passar livremente ponteiros de objeto derivados MFC ou MFC entre um aplicativo e as DLLs de extensão do MFC que ele carrega.

Uma DLL de extensão do MFC usa uma versão compartilhada do MFC da mesma maneira que um aplicativo usa a versão da DLL compartilhada do MFC, com algumas considerações adicionais:

- Ele não tem um `CWinApp`objeto derivado. Ele deve funcionar com o `CWinApp`objeto derivado do aplicativo cliente. Isso significa que o aplicativo cliente possui o bombeamento principal da mensagem, o loop ocioso e assim por diante.

- Ele chama `AfxInitExtensionModule` sua `DllMain` função. O valor de retorno dessa função deve ser verificado. Se um valor zero for retornado de `AfxInitExtensionModule`, retorne 0 de `DllMain` sua função.

- Ele cria um objeto **CDynLinkLibrary** durante a inicialização se a DLL de extensão do MFC `CRuntimeClass` quiser exportar objetos ou recursos para o aplicativo.

Antes da versão 4,0 do MFC, esse tipo de DLL era chamado de AFXDLL. AFXDLL refere-se `_AFXDLL` ao símbolo de pré-processador que é definido durante a criação da dll.

As bibliotecas de importação para a versão compartilhada do MFC são nomeadas de acordo com a Convenção descrita em [convenções de nomenclatura para DLLs do MFC](../mfc/mfc-library-versions.md#mfc-static-library-naming-conventions). O Visual Studio fornece versões predefinidas das DLLs do MFC, além de várias DLLs não-MFC que você pode usar e distribuir com seus aplicativos. Eles são documentados em Redist. txt, que é instalado na pasta Program Files\Microsoft Visual Studio.

Se você estiver exportando usando um arquivo. def, coloque o seguinte código no início e no final do arquivo de cabeçalho:

```cpp
#undef AFX_DATA
#define AFX_DATA AFX_EXT_DATA
// <body of your header file>
#undef AFX_DATA
#define AFX_DATA
```

Essas quatro linhas garantem que o código seja compilado corretamente para uma DLL de extensão do MFC. Deixar essas quatro linhas pode fazer com que a DLL seja compilada ou vinculada incorretamente.

Se você precisar passar um ponteiro de objeto derivado de MFC ou MFC para ou de uma DLL do MFC, a DLL deverá ser uma DLL de extensão do MFC. As funções de membro associadas ao objeto passado existem no módulo em que o objeto foi criado. Como essas funções são exportadas corretamente ao usar a versão de DLL compartilhada do MFC, você pode passar livremente ponteiros de objeto derivados MFC ou MFC entre um aplicativo e as DLLs de extensão do MFC que ele carrega.

Devido a problemas de descadastramento e exportação de nome do C++, a lista de exportação de uma DLL de extensão do MFC pode ser diferente entre as versões de depuração e de varejo da mesma DLL e DLLs para diferentes plataformas. O Retail MFCx0. dll tem cerca de 2.000 pontos de entrada exportados; o Debug MFCx0D. dll tem cerca de 3.000 pontos de entrada exportados.

## <a name="memory-management"></a>Gerenciamento de memória

MFCx0. dll e todas as DLLs de extensão do MFC carregadas no espaço de endereço de um aplicativo cliente usam o mesmo alocador de memória, carregamento de recursos e outros Estados globais do MFC como se estivessem no mesmo aplicativo. Isso é significativo porque as bibliotecas de DLL não MFC e as DLLs regulares do MFC fazem o oposto exato e têm cada DLL alocando-se de seu próprio pool de memória.

Se uma DLL de extensão do MFC alocar memória, essa memória poderá misturar livremente com qualquer outro objeto alocado pelo aplicativo. Além disso, se um aplicativo que vincula dinamicamente ao MFC falhar, a proteção do sistema operacional manterá a integridade de qualquer outro aplicativo MFC que compartilha a DLL.

Da mesma forma, outros Estados de MFC globais, como o arquivo executável atual para carregar recursos, também são compartilhados entre o aplicativo cliente e todas as DLLs de extensão do MFC, bem como o MFCx0. dll em si.

## <a name="sharing-resources-and-classes"></a>Compartilhando recursos e classes

A exportação de recursos é feita por meio de uma lista de recursos. Cada aplicativo contém uma lista vinculada individualmente de objetos **CDynLinkLibrary** . Ao procurar um recurso, a maioria das implementações padrão do MFC que carregam os recursos parecem primeiro no módulo do`AfxGetResourceHandle`recurso atual () e, se o recurso não for encontrado, percorra a lista de objetos **CDynLinkLibrary** tentando carregar o recurso solicitado.

A movimentação da lista tem as desvantagens de que é um pouco mais lenta e requer o gerenciamento de intervalos de ID de recurso. Ele tem a vantagem de que um aplicativo cliente que se vincula a várias DLLs de extensão MFC pode usar qualquer recurso fornecido por DLL sem precisar especificar o identificador da instância de DLL. `AfxFindResourceHandle`é uma API usada para percorrer a lista de recursos para procurar uma determinada correspondência. Ele usa o nome e o tipo de um recurso e retorna o identificador de recurso onde ele foi encontrado pela primeira vez (ou nulo).

Se você não quiser percorrer a lista e carregar apenas os recursos de um local específico, use as funções `AfxGetResourceHandle` e `AfxSetResourceHandle` para salvar o identificador antigo e definir o novo identificador. Certifique-se de restaurar o identificador de recurso antigo antes de retornar para o aplicativo cliente. Para obter um exemplo de como usar essa abordagem para carregar explicitamente um menu, consulte Testdll2. cpp no exemplo do MFC [DLLHUSK](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/MFC/advanced/dllhusk).

A criação dinâmica de objetos MFC de acordo com um nome MFC é semelhante. O mecanismo de desserialização do objeto MFC precisa ter todos os `CRuntimeClass` objetos registrados para que possa reconstruir criando dinamicamente objetos C++ do tipo necessário com base no que foi armazenado anteriormente.

No caso do exemplo de MFC [DLLHUSK](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/MFC/advanced/dllhusk), a lista é semelhante a:

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

em que *XX* é o número de versão; por exemplo, 42 representa a versão 4,2.

Normalmente, o MFCxx. dll é o último na lista de recursos e classes. O MFCxx. dll inclui todos os recursos padrão do MFC, incluindo cadeias de caracteres de prompt para todas as IDs de comando padrão. Colocá-lo no final da lista permite que as DLLs e o próprio aplicativo cliente não tenham sua própria cópia dos recursos padrão do MFC, mas para contar com os recursos compartilhados no MFCxx. dll em vez disso.

Mesclar os recursos e os nomes de classe de todas as DLLs no espaço de nome do aplicativo cliente tem a desvantagem de exigir que você tenha cuidado com quais IDs ou nomes você escolhe.

O exemplo [DLLHUSK](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/MFC/advanced/dllhusk) gerencia o espaço de nome de recurso compartilhado usando vários arquivos de cabeçalho.

Se a DLL de extensão do MFC precisar manter dados adicionais para cada aplicativo, você poderá derivar uma nova classe de **CDynLinkLibrary** e criá `DllMain`-la no. Durante a execução, a DLL pode verificar a lista atual de objetos **CDynLinkLibrary** do aplicativo para encontrar aquele para essa DLL de extensão de MFC específica.

### <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Inicializar uma DLL de extensão do MFC](run-time-library-behavior.md#initializing-extension-dlls)

### <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [Dicas sobre como usar arquivos de recursos compartilhados](../mfc/tn035-using-multiple-resource-files-and-header-files-with-visual-cpp.md)

- [Versão da DLL do MFC](../mfc/tn033-dll-version-of-mfc.md)

- [DLLs MFC regulares vinculadas estaticamente ao MFC](regular-dlls-statically-linked-to-mfc.md)

- [DLLs MFC regulares vinculadas dinamicamente ao MFC](regular-dlls-dynamically-linked-to-mfc.md)

- [Usando DLLs de extensão do banco de dados, OLE e sockets do MFC em DLLs comuns do MFC](using-database-ole-and-sockets-extension-dlls-in-regular-dlls.md)

## <a name="see-also"></a>Confira também

[Criar DLLs C /C++ no Visual Studio](dlls-in-visual-cpp.md)
