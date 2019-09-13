---
title: Usando os arquivos de origem MFC
ms.date: 08/19/2019
helpviewer_keywords:
- public members
- source files
- MFC, source files
- MFC source files
- comments, MFC
- private member access
- protected member access
- source files, MFC
ms.assetid: 3230e8fb-3b69-4ddf-9538-365ac7ea5e72
ms.openlocfilehash: ca5799da7a6ada42db20e3551b3fb7262e8990a0
ms.sourcegitcommit: 9d4ffb8e6e0d70520a1e1a77805785878d445b8a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/20/2019
ms.locfileid: "69631674"
---
# <a name="using-the-mfc-source-files"></a>Usando os arquivos de origem MFC

A biblioteca do MFC (Microsoft Foundation Class) fornece código-fonte completo. Os arquivos de cabeçalho (. h) estão no diretório *\atlmfc\include* Os arquivos de implementação (. cpp) estão no diretório *\atlmfc\src\mfc*

Este artigo explica as convenções que o MFC usa para comentar as várias partes de cada classe, o que significam esses comentários e o que você deve esperar encontrar em cada seção. Os assistentes do Visual Studio usam convenções semelhantes para as classes que criam para você, e você provavelmente encontrará essas convenções úteis para seu próprio código.

Você pode estar familiarizado com as palavras-chave **pública**, **protegida**e **privada** C++ . Nos arquivos de cabeçalho do MFC, você encontrará que cada classe pode ter vários deles. Por exemplo, variáveis de membro público e funções podem estar em mais de uma palavra-chave **pública** . É porque o MFC separa variáveis de membro e funções com base em seu uso, não pelo tipo de acesso permitido. O MFC **usa de** forma moderada. Até mesmo os itens considerados detalhes de implementação geralmente são **protegidos**e muitas vezes são **públicos**. Embora o acesso aos detalhes da implementação seja desencorajado, o MFC deixa a decisão para você.

Nos arquivos de origem do MFC e nos arquivos de cabeçalho criados pelo assistente de aplicativo do MFC, você encontrará comentários como esses dentro de declarações de classe (geralmente nesta ordem):

`// Constructors`

`// Attributes`

`// Operations`

`// Overridables`

`// Implementation`

## <a name="an-example-of-the-comments"></a>Um exemplo dos comentários

A listagem parcial de classe `CStdioFile` a seguir usa a maioria dos comentários padrão que o MFC emprega em suas classes para dividir os membros da classe de acordo com as maneiras que eles são usados:

```cpp
/*============================================================================*/
// STDIO file implementation

class CStdioFile : public CFile
{
    DECLARE_DYNAMIC(CStdioFile)

public:
// Constructors
    CStdioFile();

    // . . .

// Attributes
    FILE* m_pStream;    // stdio FILE
                        // m_hFile from base class is _fileno(m_pStream)

// Operations
    // reading and writing strings
    virtual void WriteString(LPCTSTR lpsz);
    virtual LPTSTR ReadString(_Out_writes_z_(nMax) LPTSTR lpsz, _In_ UINT nMax);
    virtual BOOL ReadString(CString& rString);

// Implementation
public:
    virtual ~CStdioFile();
#ifdef _DEBUG
    void Dump(CDumpContext& dc) const;
#endif
    virtual ULONGLONG GetPosition() const;
    virtual ULONGLONG GetLength() const;
    virtual BOOL Open(LPCTSTR lpszFileName, UINT nOpenFlags, CFileException* pError = NULL);

    // . . .

protected:
    void CommonBaseInit(FILE* pOpenStream, CAtlTransactionManager* pTM);
    void CommonInit(LPCTSTR lpszFileName, UINT nOpenFlags, CAtlTransactionManager* pTM);
};
```

Esses comentários marcam consistentemente as seções da declaração de classe que contêm tipos semelhantes de membros de classe. Tenha em mente que eles são convenções de MFC, não definir regras.

## <a name="-constructors-comment"></a>Comentário de construtores

A `// Constructors` seção de uma declaração de classe MFC declara construtores (no C++ sentido) e todas as funções de inicialização necessárias para realmente usar o objeto. Por exemplo, `CWnd::Create` está na seção construtores porque antes de usar o `CWnd` objeto, ele deve ser "totalmente construído" chamando primeiro o C++ Construtor e, em seguida, chamando a `Create` função. Normalmente, esses membros são públicos.

Por exemplo, a `CStdioFile` classe tem cinco construtores, um dos quais é mostrado na listagem sob [um exemplo dos comentários](#an-example-of-the-comments).

## <a name="-attributes-comment"></a>Comentário de atributos

A `// Attributes` seção de uma declaração de classe MFC contém os atributos públicos (ou Propriedades) do objeto. Normalmente, os atributos são variáveis de membro ou as funções get/set. As funções "Get" e "set" podem ou não ser virtuais. As funções "Get" geralmente são **constantes**, porque na maioria dos casos eles não têm efeitos colaterais. Esses membros são normalmente públicos. Os atributos protegidos e privados normalmente são encontrados na seção implementação.

Na listagem de exemplo da classe `CStdioFile`, em [um exemplo dos comentários](#an-example-of-the-comments), a lista inclui uma variável de membro, *m_pStream*. Classe `CDC` lista quase 20 membros sob este comentário.

> [!NOTE]
> Classes grandes, como `CDC` e `CWnd`, podem ter tantos membros que simplesmente listando todos os atributos em um grupo não adicionariam muito à clareza. Nesses casos, a biblioteca de classes usa outros comentários como títulos para delinear ainda mais os membros. Por exemplo, `CDC` usa `// Device-Context Functions`, `// Drawing Tool Functions` ,emais.`// Drawing Attribute Functions` Os grupos que representam atributos seguirão a sintaxe usual descrita acima. Muitas classes OLE têm uma seção de implementação `// Interface Maps`chamada.

## <a name="-operations-comment"></a>Comentário de operações

A `// Operations` seção de uma declaração de classe MFC contém funções membro que você pode chamar no objeto para fazer coisas ou executar ações (executar operações). Normalmente, essas funções não são**constantes** porque normalmente têm efeitos colaterais. Elas podem ser virtuais ou não virtuais, dependendo das necessidades da classe. Normalmente, esses membros são públicos.

Na listagem de exemplo da classe `CStdioFile`, em [um exemplo dos comentários](#an-example-of-the-comments), a lista inclui três funções de membro neste comentário: `WriteString` e duas sobrecargas de. `ReadString`

Assim como acontece com os atributos, as operações podem ser mais subdivididas.

## <a name="-overridables-comment"></a>Comentário de Overridable

A `// Overridables` seção de uma declaração de classe MFC contém funções virtuais que podem ser substituídas em uma classe derivada quando você precisa modificar o comportamento da classe base. Normalmente, eles são nomeados começando com "on", embora não seja estritamente necessário. As funções aqui são projetadas para serem substituídas e, muitas vezes, implementam ou fornecem algum tipo de "retorno de chamada" ou "gancho". Normalmente, esses membros são protegidos.

No próprio MFC, as funções virtuais puras são sempre colocadas nesta seção. Uma função virtual pura no C++ assume a forma:

`virtual void OnDraw( ) = 0;`

Na listagem de exemplo da classe `CStdioFile`, em [um exemplo dos comentários](#an-example-of-the-comments), a lista não inclui nenhuma seção substituível. Por `CDocument`outro lado, a classe lista aproximadamente 10 funções de membro substituíveis.

Em algumas classes, você também pode ver o comentário `// Advanced Overridables`. Essas funções são aquelas que apenas os programadores avançados devem tentar substituir. Você provavelmente nunca precisará substituí-los.

> [!NOTE]
> As convenções descritas neste artigo também funcionam bem, em geral, para métodos e propriedades de automação (anteriormente conhecidos como automação OLE). Os métodos de automação são semelhantes às operações do MFC. As propriedades de automação são semelhantes aos atributos do MFC. Os eventos de automação (com suporte para controles ActiveX, anteriormente conhecidos como controles OLE) são semelhantes às funções de membro substituíveis do MFC.

## <a name="-implementation-comment"></a>Comentário de implementação

A `// Implementation` seção é a parte mais importante de qualquer declaração de classe do MFC.

Esta seção hospeda todos os detalhes de implementação. As variáveis de membro e as funções de membro podem aparecer nesta seção. Tudo abaixo dessa linha pode ser alterado em uma versão futura do MFC. A menos que não seja possível evitá-lo, não se deve `// Implementation` depender dos detalhes abaixo da linha. Além disso, os membros declarados abaixo da linha de implementação não são documentados, embora algumas implementações sejam discutidas em notas técnicas. As substituições de funções virtuais na classe base residem nesta seção, independentemente da seção em que a função de classe base está definida. Quando uma função substitui a implementação da classe base, ela é considerada um detalhe de implementação. Normalmente, esses membros são protegidos, mas nem sempre.

Na listagem `CStdioFile` sob [um exemplo de comentários](#an-example-of-the-comments), os membros declarados abaixo do comentário `// Implementation` podem ser declarados como **públicos**, **protegidos** ou **privados**. Use esses membros somente com cuidado, pois eles podem ser alterados no futuro. A declaração de um grupo de membros como **público** pode ser necessária para que a implementação da biblioteca de classes funcione corretamente. No entanto, isso não significa que você pode usar com segurança os membros, portanto declarados.

> [!NOTE]
> Você pode encontrar comentários sobre os tipos restantes acima ou abaixo do `// Implementation` comentário. Em ambos os casos, eles descrevem os tipos de membros declarados abaixo deles. Se eles ocorrerem abaixo `// Implementation` do comentário, você deve assumir que os membros podem ser alterados em versões futuras do MFC.

## <a name="see-also"></a>Consulte também

[Tópicos gerais do MFC](../mfc/general-mfc-topics.md)
