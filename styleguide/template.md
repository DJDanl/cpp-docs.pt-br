# <a name="metadata-and-markdown-template"></a>Metadados e modelo Markdown

Esse modelo de documentos básicos contém exemplos da sintaxe Markdown, bem como diretrizes de definição dos metadados. Para aproveitá-la ao máximo, é necessário exibir o [Markdown bruto](https://raw.githubusercontent.com/dotnet/docs/master/styleguide/template.md) e a [exibição renderizada](https://github.com/dotnet/docs/blob/master/styleguide/template.md) (por exemplo, o Markdown bruto mostra o bloco de metadados, ao contrário da exibição renderizada).

Ao criar um arquivo Markdown, é necessário copiar esse modelo para um novo arquivo, preencher os metadados conforme especificado abaixo, definir o cabeçalho H1 acima do título do artigo e excluir o conteúdo.

## <a name="metadata"></a>Metadados

O bloco de metadados completo é mostrado acima (no [Markdown bruto](https://raw.githubusercontent.com/dotnet/docs/master/styleguide/template.md)), dividido em campos obrigatórios e opcionais. Algumas observações importantes:

- **Deve** haver um espaço entre os dois-pontos (:) e o valor de um elemento de metadados.
- Se um elemento de metadados opcional não tiver um valor, comente o elemento com um # ou remova-o (não o deixe em branco nem use “na”); se estiver adicionando um valor a um elemento que foi comentado, lembre-se de remover o #.
- Dois-pontos em um valor (por exemplo, um título) quebram o analisador de metadados. Nesse caso, coloque o título entre aspas duplas (por exemplo, `title: "Writing .NET Core console apps: An advanced step-by-step guide"`).
- **title**: esse título aparecerá nos resultados do mecanismo de pesquisa. Você também pode adicionar um pipe (|) seguido pelo nome do produto (por exemplo, `title: Developing Libraries with Cross Platform Tools | .NET Core`). O título não precisa ser idêntico ao título do cabeçalho H1 e deve conter 65 caracteres ou menos (incluindo | NOME DO PRODUTO).
- **author**, **manager**, **ms.reviewer**: o campo autor deve conter o **nome de usuário do GitHub** do autor, não seu alias.  Por outro lado, os campos “manager” e “ms.reviewer” devem conter aliases da Microsoft. ms.reviewer especifica o nome do PM/desenvolvedor associado ao artigo ou ao recurso.
- **ms.devlang** define a tecnologia. Alguns dos valores compatíveis são: `dotnet`, `cpp`, `csharp`, `fsharp`, `vb` e `xml`.
- **ms.assetid**: esse é o GUID do artigo usado para fins de acompanhamento interno, como BI (Business Intelligence). Ao criar um novo arquivo Markdown, é possível obter um GUID do [Gerador de GUID Online](https://www.guidgenerator.com/).

## <a name="basic-markdown-gfm-and-special-characters"></a>Marcação básica, GFM e caracteres especiais

Há suporte para todo o GFM (GitHub Flavored Markdown) e básico. Para obter mais informações sobre eles, consulte:

- [Sintaxe Markdown de linha de base](https://daringfireball.net/projects/markdown/syntax)
- [Documentação de GFM](https://guides.github.com/features/mastering-markdown)

O Markdown usa caracteres especiais, como \*, \` e \# para formatação. Se desejar incluir um desses caracteres no conteúdo, realize uma destas ações:

- Coloque uma barra invertida antes do caractere especial para inserir “escape” nele (por exemplo, `\*` para um \*)
- Use o [código de entidade HTML](https://www.ascii.cl/htmlcodes.htm) do caractere (por exemplo, `&#42;` para um &#42;).

## <a name="markdown-editing-tools"></a>Ferramentas de edição de Markdown

É possível usar o [Visual Studio Code](https://code.visualstudio.com/) para editar documentos de Markdown. O VS Code tem muitas extensões úteis de Markdown, como:

- [docs-markdown](https://marketplace.visualstudio.com/items?itemName=docsmsft.docs-markdown) da Microsoft
- [markdownlint](https://marketplace.visualstudio.com/items?itemName=DavidAnson.vscode-markdownlint)

## <a name="file-name"></a>Nome do arquivo

Os nomes de arquivo usam as seguintes regras:

- Conter apenas letras minúsculas, números e hifens.
- Sem espaços nem caracteres de pontuação. Use os hifens para separar palavras e números no nome do arquivo.
- Use verbos de ação específicos, como desenvolver, comprar, compilar, solucionar problemas. Sem palavras no gerúndio.
- Sem palavras pequenas – não inclua artigos nem preposições.
- Deve estar em Markdown e usar a extensão de arquivo .md.
- Mantenha os nomes de arquivo razoavelmente curtos. Eles fazem parte da URL dos artigos.  

## <a name="headings"></a>Títulos

Use a capitalização de estilo da frase. Sempre coloque em maiúsculas:

- A primeira palavra de um cabeçalho.
- A palavra após dois-pontos em um título ou cabeçalho (por exemplo, “Como: classificar uma matriz”).

Os cabeçalhos devem ser feitos usando o atx-style ou seja, use de 1 a 6 caracteres de hash (#) no início da linha para indicar um cabeçalho correspondente aos níveis de cabeçalho HTML de H1 a H6. Exemplos de cabeçalhos de primeiro e segundo nível são usados acima.

**Deve** haver apenas um cabeçalho de primeiro nível (H1) no tópico, que será exibido como o título na página.

Se o cabeçalho terminar com um `#` caractere, você precisará adicionar um caractere `#` extra ao final para que o título seja renderizado corretamente. Por exemplo, `# Async Programming in F# #`.

Sempre deve haver uma linha em branco antes e depois de um título (salvo para títulos de primeiro nível).

Os cabeçalhos de segundo nível gerarão o Sumário na página exibida na seção “Neste artigo” sob o título na página.

```markdown
### Third-level heading

#### Fourth-level heading

##### Fifth level heading

###### Sixth-level heading
```

## <a name="text-styling"></a>Estilo do texto

*Itálico*  
Use para nomes de arquivo, pastas e caminhos gerados pelo usuário (para itens longos, divida nas próprias linhas); novos termos; nomes de parâmetro; valores inseridos pelo usuário e URLs (salvo se renderizadas como links, que é o padrão).

**Negrito**  
Use para elementos da interface do usuário e palavras-chave de linguagem de programação.

## <a name="links"></a>Links

### <a name="internal-links"></a>Links internos

Para vincular a um cabeçalho no mesmo arquivo Markdown (também conhecido como links do tipo âncora), você precisará descobrir a ID do cabeçalho à qual está tentando vincular. Para confirmar a ID, exiba a origem do artigo renderizado, localize a ID do cabeçalho (por exemplo, `id="blockquote"`) e vincule-a usando # + ID (por exemplo, `#blockquote`).
A ID é gerada automaticamente com base no texto do cabeçalho. Assim, por exemplo, considerando uma seção exclusiva chamada `## Step 2`, a ID terá a aparência deste `id="step-2"`.

- Exemplo: [Capítulo 1](#chapter-1)

Para vincular a um arquivo Markdown no mesmo repositório, use [links relativos](https://www.w3.org/TR/WD-html40-970917/htmlweb.html#h-5.1.2), incluindo o “.md” ao final do nome de arquivo.

- Exemplo: [Arquivo Leiame](../readme.md)
- Exemplo: [Bem-vindo ao .NET](../docs/welcome.md)

Para vincular a um cabeçalho em um arquivo Markdown no mesmo repositório, use a vinculação relativa + vinculação de hashtag.

- Exemplo: [Comunidade do .NET](../docs/welcome.md#community)

### <a name="docs-links"></a>Links do Docs

Para vincular a um arquivo em um repositório diferente do Docs, use como link a URL relativa do docs.microsoft.com. Não inclua o sufixo .md.

- Exemplo: [documentação da Plataforma Universal do Windows](/windows/uwp)

### <a name="external-links"></a>Links externos

Para vincular a um arquivo externo, use a URL completa como o link. Use a URL HTTPS, se aplicável.

- Exemplo: [GitHub](https://www.github.com)

Se uma URL for exibida em um arquivo Markdown, ela será transformada em um link clicável.

- Exemplo: https://www.github.com

### <a name="links-to-apis"></a>Links para APIs

O sistema de build tem algumas extensões que nos permitem vincular a APIs do .NET Core sem a necessidade de usar links externos.  
Ao vincular a uma API, é possível usar seu UID (identificador exclusivo) que é gerado automaticamente com base no código-fonte.

É possível usar uma das seguintes sintaxes:

1. Link de markdown: `[link_text](xref:UID)`
2. Link automático: `<xref:UID>`
3. Forma abreviada: `@UID`

- Exemplo: `@System.String`
- Exemplo: `[String class](xref:System.String)`

Para obter mais informações sobre como usar essa notação, consulte [Using cross reference](https://dotnet.github.io/docfx/tutorial/links_and_cross_references.html#using-cross-reference) (Usando a referência cruzada).

> No momento, não há uma maneira fácil de encontrar os UIDs. A melhor maneira de encontrar a UID de uma API é pesquisá-la neste repositório: [docascode/coreapi](https://github.com/docascode/coreapi). Estamos trabalhando para ter um sistema melhor no futuro.

Quando o UID contém os caracteres especiais \` ou \#, o valor do UID precisa ser codificado em HTML como %60 e %23, respectivamente, como nos seguintes exemplos:
- Exemplo: @System.Threading.Tasks.Task\`1 torna-se `@System.Threading.Tasks.Task%601`
- Exemplo: @System.Exception.\#ctor torna-se `@System.Exception.%23ctor`

## <a name="lists"></a>Listas

As listas devem ser circundadas por linhas em branco.

### <a name="ordered-lists"></a>Listas ordenadas

1. Este
1. É
1. Uma
1. Ordenada
1. Lista

#### <a name="ordered-list-with-an-embedded-list"></a>Lista ordenada com uma lista inserida

1. Esta
1. é
1. uma
1. lista
    1. Senhorita Costa
    1. Professor Mendes
1. ordered
1. lista

### <a name="unordered-lists"></a>Listas não ordenadas

- Este
- is
- a
- com marcadores
- lista

#### <a name="unordered-list-with-an-embedded-list"></a>Lista não ordenada com uma lista inserida

- Este
- com marcadores
- lista
    - Sra. Pereira
    - Sr. Martins
- contém  
- outras
    1. Coronel Teixeira
    1. Sra. Barbosa
- listas

## <a name="horizontal-rule"></a>Régua horizontal

___

## <a name="tables"></a>Tabelas

| Tabelas        | São           | Legais  |
| ------------- |:-------------:| -----:|
| A coluna 3 está      | alinhada à direita | US$ 1.600 |
| A coluna 2 está      | centralizada      |   US$ 12 |
| A coluna 1 está por padrão | alinhada à esquerda     |    US$ 1 |

É possível usar uma [ferramenta de gerador de tabelas Markdown](https://www.tablesgenerator.com/markdown_tables) para ajudar a criá-las com mais facilidade. Confira também [ferramentas de edição de Markdown](#markdown-editing-tools).

## <a name="code"></a>Código

A melhor maneira de incluir código é incluir snippets de uma amostra funcional. Crie a amostra seguindo as instruções do [guia de contribuição](../CONTRIBUTING.md#contributing-to-samples).

É possível incluir o código usando a sintaxe de inclusão:

```markdown
[!code-csharp[<title>](<pathToFile>#<RegionName)]
```

O exemplo acima mostra a sintaxe C#, mas há suporte para outras linguagens.
Use `code-fsharp` para amostras do F#; use `code-vbnet` para amostras do Visual Basic.
Outras linguagens com suporte são:

- C++: `code-cpp`
- HTML: `code-html`
- JavaScript: `code-javascript`
- PowerShell: `code-ps`
- SQL: `code-sql`
- XML: `code-xml`

O texto colocado para `<title>` aparece como uma sobreposição no texto. O `<pathToFile>` é o caminho para o arquivo de origem. O `<RegionName>` deve ser uma região no código-fonte que deve ser incluída. Use a sintaxe do pré-processador `#region` e `#endregion` para especificar a região de código a ser incluída.

Para casos em que as regiões não funcionam, é possível especificar o início e término de um snippet usando um nome de elemento XML em um comentário de linha única. Por exemplo, é possível escrever isto em C#:

```csharp
// <CodeToInclude>
int j = 5;
int i ; 10;
int sum = i + j;
// </CodeToInclude>
```

Em outras linguagens, use a sintaxe de comentário da linguagem.

Finalmente, é possível usar números de linha: `#L1-L10` incluirá as linhas 1 a 10. Não incentivamos o uso de números de linha, pois são muito frágeis.

A inclusão de snippets de programas completos garante que todo o código é executado por meio de nosso sistema de CI (Integração Contínua). No entanto, se você precisar mostrar algo que causa erros de tempo de compilação ou de execução, será possível usar blocos de código embutidos.

### <a name="inline-code-blocks-with-language-identifier"></a>Blocos de código embutidos com identificador de linguagem

Use três backticks (\`\`\`) + uma ID de idioma para aplicar a codificação de cores específico a um idioma para um bloco de código. Esta é a lista inteira de [IDs de linguagem de GFM](https://github.com/jmm/gfm-lang-ids/wiki/GitHub-Flavored-Markdown-(GFM)-language-IDs).

#### <a name="c"></a>C\#

```csharp
using System;
namespace HelloWorld
{
    class Hello
    {
        static void Main() 
        {
            Console.WriteLine("Hello World!");

            // Keep the console window open in debug mode.
            Console.WriteLine("Press any key to exit.");
            Console.ReadKey();
        }
    }
}
```

#### <a name="python"></a>Python

```python
friends = ['john', 'pat', 'gary', 'michael']
for i, name in enumerate(friends):
    print "iteration {iteration} is {name}".format(iteration=i, name=name)
```

#### <a name="powershell"></a>PowerShell

```powershell
Clear-Host
$Directory = "C:\Windows\"
$Files = Get-Childitem $Directory -recurse -Include *.log `
-ErrorAction SilentlyContinue
```

### <a name="generic-code-block"></a>Bloco de código genérico

Use três backticks (&#96;&#96;&#96;) para a codificação de bloco de código genérico.

> A abordagem recomendada é usar blocos de código com identificadores de linguagem, conforme explicado na seção anterior, para garantir o realce de sintaxe apropriado no site da documentação. Use blocos de código genérico somente quando necessário.

```javascript
function fancyAlert(arg) {
    if(arg) {
        $.docs({div:'#foo'})
    }
}
```

### <a name="inline-code"></a>Código embutido

Use backticks (&#96;) para `inline code`. Use código embutido para comandos da linha de comando, para nomes de coluna e de tabela de banco de dados e nomes de função e de expressão de linguagem.

## <a name="blockquotes"></a>Blockquotes

> A seca agora se estende para dez milhões de anos e o reino dos terríveis lagartos desde então foi extinto. Aqui no Equador, no continente em que um dia seria conhecido como África, a luta pela existência atingiu um novo auge de ferocidade e o vencedor ainda não foi avistado. Nesta terra árida e desidratada, apenas as espécies pequenas, ágeis ou ferozes poderiam prosperar ou mesmo ter a esperança de sobreviver.

## <a name="images"></a>Imagens

### <a name="static-image-or-animated-gif"></a>Imagem estática ou GIF animado

![este é o texto Alt](../images/Logo_DotNet.png)

### <a name="linked-image"></a>Imagem vinculada

[![texto Alt da imagem vinculada](../images/Logo_DotNet.png)](https://dot.net)

## <a name="videos"></a>Vídeos

### <a name="channel-9"></a>Channel 9

[![Larry Osterman – sua interação com Bill Gates (sobre a pilha de rede DOS)](https://sec.ch9.ms/ch9/caf5/f8657a22-5b83-47a3-9748-4c1be9fecaf5/Larry-Osterman-His-one-interaction-with-Bill-Gate_960.jpg)
](https://channel9.msdn.com/Blogs/TheChannel9Team/Larry-Osterman-His-one-interaction-with-Bill-Gates-over-DOS-networking-stack)

### <a name="youtube"></a>YouTube

[![No .NET 4/2/2016 – Scott Hunter](https://img.youtube.com/vi/g2a4W6Q7aRw/0.jpg)
](https://www.youtube.com/watch?v=g2a4W6Q7aRw)

## <a name="docsmicrosoft-extensions"></a>Extensões docs.microsoft

O docs.microsoft fornece algumas extensões adicionais para o GitHub Flavored Markdown. 

### <a name="alerts"></a>Alertas

É importante usar os estilos de alerta a seguir para que eles sejam renderizados com o estilo adequado no site da documentação. No entanto, o mecanismo de renderização no GitHub não os diferencia.

#### <a name="note"></a>Observação

> [!NOTE]
> Essa é uma OBSERVAÇÃO

#### <a name="warning"></a>Aviso

> [!WARNING]
> Esse é um AVISO

#### <a name="tip"></a>Dica

> [!TIP]
> Essa é uma DICA

#### <a name="important"></a>Importante

> [!IMPORTANT]
> Isso é IMPORTANTE

E eles serão renderizados assim: ![Estilos de alerta](../images/alerts.png)

### <a name="buttons"></a>Botões

> [!div class="button"]
[links de botão](../docs/core/index.md)

É possível ver um exemplo de botões em ação no [Intune Docs](https://docs.microsoft.com/intune/get-started/choose-how-to-enroll-devices). 

### <a name="selectors"></a>Seletores

> [!div class="op_single_selector"]
- [macOS](../docs/core/tutorials/using-on-macos.md)
- [Windows](../docs/core/tutorials/using-on-windows.md)

É possível ver um exemplo de seletores em ação no [Intune Docs](https://docs.microsoft.com/intune/deploy-use/what-to-tell-your-end-users-about-using-microsoft-intune#how-your-end-users-get-their-apps).

### <a name="step-by-steps"></a>Passo a passo

>[!div class="step-by-step"]
[Anterior](../docs/csharp/expression-trees-interpreting.md)
[Próximo](../docs/csharp/expression-trees-translating.md)

É possível ver um exemplo de passo a passo em ação no [Advanced Threat Analytics Docs](https://docs.microsoft.com/advanced-threat-analytics/deploy-use/install-ata-step2).
