---
title: Noções básicas de SAL
ms.date: 11/04/2016
ms.topic: conceptual
ms.assetid: a94d6907-55f2-4874-9571-51d52d6edcfd
ms.openlocfilehash: 30f001214610c424dc8ea4bcc971c6e39e9f2571
ms.sourcegitcommit: 6b749db14b4cf3a2b8d581fda6fdd8cb98bc3207
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/05/2020
ms.locfileid: "82825724"
---
# <a name="understanding-sal"></a>Noções básicas de SAL

O SAL (código-fonte de nota) da Microsoft fornece um conjunto de anotações que você pode usar para descrever como uma função usa seus parâmetros, as suposições que ele faz sobre eles e as garantias que ele faz quando é concluído. As anotações são definidas no arquivo `<sal.h>`de cabeçalho. A análise de código do Visual Studio para C++ usa anotações SAL para modificar sua análise de funções. Para obter mais informações sobre o SAL 2,0 para o desenvolvimento de drivers do Windows, consulte [sal 2,0 anotações para drivers do Windows](/windows-hardware/drivers/devtest/sal-2-annotations-for-windows-drivers).

Nativamente, C e C++ fornecem apenas maneiras limitadas para os desenvolvedores expressem consistentemente a intenção e a invariância. Usando anotações SAL, você pode descrever suas funções com mais detalhes para que os desenvolvedores que as estejam consumindo possam entender melhor como usá-las.

## <a name="what-is-sal-and-why-should-you-use-it"></a>O que é SAL e por que você deve usá-lo?

Simplesmente declarado, SAL é uma maneira barata de permitir que o compilador Verifique seu código para você.

### <a name="sal-makes-code-more-valuable"></a>SAL torna o código mais valioso

O SAL pode ajudá-lo a tornar seu design de código mais compreensível, tanto para seres humanos quanto para ferramentas de análise de código. Considere este exemplo que mostra a função `memcpy`de tempo de execução C:

```cpp

void * memcpy(
   void *dest,
   const void *src,
   size_t count
);
```

Você pode dizer o que essa função faz? Quando uma função é implementada ou chamada, determinadas propriedades devem ser mantidas para garantir a exatidão do programa. Apenas olhando para uma declaração como a do exemplo, você não sabe o que eles são. Sem anotações de SAL, você precisaria confiar na documentação ou nos comentários de código. Veja o que a documentação do MSDN `memcpy` diz:

> "Copia bytes de contagem de src para dest. Se a origem e o destino se sobrepõem, o comportamento de memcpy é indefinido. Use memmove para lidar com regiões sobrepostas. \
> **Observação de segurança:** Verifique se o buffer de destino tem o mesmo tamanho ou maior que o buffer de origem. Para obter mais informações, consulte evitando estouros de buffer.

A documentação contém alguns bits de informações que sugerem que seu código tem de manter determinadas propriedades para garantir a exatidão do programa:

- `memcpy`Copia o `count` de bytes do buffer de origem para o buffer de destino.

- O buffer de destino deve ser pelo menos tão grande quanto o buffer de origem.

No entanto, o compilador não pode ler a documentação ou comentários informais. Não sabe que há uma relação entre os dois buffers e `count`, e também não pode imaginar efetivamente uma relação. O SAL pode fornecer mais clareza sobre as propriedades e a implementação da função, como mostrado aqui:

```cpp

void * memcpy(
   _Out_writes_bytes_all_(count) void *dest,
   _In_reads_bytes_(count) const void *src,
   size_t count
);
```

Observe que essas anotações se assemelham às informações na documentação do MSDN, mas elas são mais concisas e seguem um padrão semântico. Ao ler esse código, você pode entender rapidamente as propriedades dessa função e como evitar problemas de segurança de saturação de buffer. Melhor ainda, os padrões semânticos que o SAL fornece podem melhorar a eficiência e a eficácia das ferramentas de análise automatizada de código na descoberta antecipada de bugs potenciais. Imagine que alguém escreva essa implementação de bugs de `wmemcpy`:

```cpp

wchar_t * wmemcpy(
   _Out_writes_all_(count) wchar_t *dest,
   _In_reads_(count) const wchar_t *src,
   size_t count)
{
   size_t i;
   for (i = 0; i <= count; i++) { // BUG: off-by-one error
      dest[i] = src[i];
   }
   return dest;
}
```

Essa implementação contém um erro comum fora de um. Felizmente, o autor do código incluiu a anotação de tamanho do buffer SAL – uma ferramenta de análise de código pode capturar o bug analisando essa função sozinha.

### <a name="sal-basics"></a>Noções básicas sobre SAL

O SAL define quatro tipos básicos de parâmetros, que são categorizados por padrão de uso.

|Categoria|Anotação de parâmetro|Descrição|
|--------------|--------------------------|-----------------|
|**Entrada para a função chamada**|`_In_`|Os dados são passados para a função chamada e são tratados como somente leitura.|
|**Entrada para a função chamada e saída para o chamador**|`_Inout_`|Os dados utilizáveis são passados para a função e potencialmente são modificados.|
|**Saída para o chamador**|`_Out_`|O chamador fornece apenas espaço para a função chamada para gravação. A função chamada grava dados nesse espaço.|
|**Saída do ponteiro para o chamador**|`_Outptr_`|Como **saída para o chamador**. O valor retornado pela função chamada é um ponteiro.|

Essas quatro anotações básicas podem se tornar mais explícitas de várias maneiras. Por padrão, os parâmetros de ponteiro anotados são considerados necessários; eles devem ser não nulos para que a função tenha sucesso. A variação mais comumente usada das anotações básicas indica que um parâmetro de ponteiro é opcional — se for nulo, a função ainda poderá ter sucesso ao fazer seu trabalho.

Esta tabela mostra como distinguir entre os parâmetros obrigatórios e opcionais:

||Parâmetros são necessários|Os parâmetros são opcionais|
|-|-----------------------------|-----------------------------|
|**Entrada para a função chamada**|`_In_`|`_In_opt_`|
|**Entrada para a função chamada e saída para o chamador**|`_Inout_`|`_Inout_opt_`|
|**Saída para o chamador**|`_Out_`|`_Out_opt_`|
|**Saída do ponteiro para o chamador**|`_Outptr_`|`_Outptr_opt_`|

Essas anotações ajudam a identificar possíveis valores não inicializados e o uso de ponteiro nulo inválido de maneira formal e precisa. Passar NULL para um parâmetro obrigatório pode causar uma falha ou pode causar a retorno de um código de erro "failed". De qualquer forma, a função não pode ter sucesso em fazer seu trabalho.

## <a name="sal-examples"></a>Exemplos de SAL

Esta seção mostra exemplos de código para as anotações SAL básicas.

### <a name="using-the-visual-studio-code-analysis-tool-to-find-defects"></a>Usando a ferramenta de análise de Visual Studio Code para encontrar defeitos

Nos exemplos, a ferramenta de análise de Visual Studio Code é usada junto com anotações SAL para encontrar defeitos de código. Veja a seguir como fazer isso.

#### <a name="to-use-visual-studio-code-analysis-tools-and-sal"></a>Para usar as ferramentas de análise de código do Visual Studio e o SAL

1. No Visual Studio, abra um projeto do C++ que contenha anotações SAL.

1. Na barra de menus, escolha **Compilar**, **executar análise de código na solução**.

     Considere o \_exemplo\_ em, nesta seção. Se você executar a análise de código, esse aviso será exibido:

    > **C6387 valor de parâmetro inválido** ' aponte ' poderia ser ' 0 ': isso não adere à especificação para a função ' incallee '.

### <a name="example-the-_in_-annotation"></a>Exemplo: a \_na\_ anotação

A `_In_` anotação indica que:

- O parâmetro deve ser válido e não será modificado.

- A função só lerá do buffer de elemento único.

- O chamador deve fornecer o buffer e inicializá-lo.

- `_In_`Especifica "somente leitura". Um erro comum é aplicar `_In_` a um parâmetro que deve ter a `_Inout_` anotação em vez disso.

- `_In_`é permitido, mas ignorado pelo analisador em escalares sem ponteiro.

```cpp
void InCallee(_In_ int *pInt)
{
   int i = *pInt;
}

void GoodInCaller()
{
   int *pInt = new int;
   *pInt = 5;

   InCallee(pInt);
   delete pInt;
}

void BadInCaller()
{
   int *pInt = NULL;
   InCallee(pInt); // pInt should not be NULL
}
```

Se você usar a análise de Visual Studio Code neste exemplo, ele validará que os chamadores passam um ponteiro não nulo para um buffer inicializado `pInt`para. Nesse caso, `pInt` o ponteiro não pode ser nulo.

### <a name="example-the-_in_opt_-annotation"></a>Exemplo: a \_anotação\_em\_ opt

`_In_opt_`é o mesmo que `_In_`, exceto que o parâmetro de entrada pode ser nulo e, portanto, a função deve verificar isso.

```cpp

void GoodInOptCallee(_In_opt_ int *pInt)
{
   if(pInt != NULL) {
      int i = *pInt;
   }
}

void BadInOptCallee(_In_opt_ int *pInt)
{
   int i = *pInt; // Dereferencing NULL pointer 'pInt'
}

void InOptCaller()
{
   int *pInt = NULL;
   GoodInOptCallee(pInt);
   BadInOptCallee(pInt);
}
```

A análise de Visual Studio Code valida que a função verifica se há NULL antes de acessar o buffer.

### <a name="example-the-_out_-annotation"></a>Exemplo: a \_anotação\_ de saída

`_Out_`dá suporte a um cenário comum no qual um ponteiro não nulo que aponta para um buffer de elemento é passado e a função inicializa o elemento. O chamador não precisa inicializar o buffer antes da chamada; a função chamada promete inicializá-la antes de retornar.

```cpp
void GoodOutCallee(_Out_ int *pInt)
{
   *pInt = 5;
}

void BadOutCallee(_Out_ int *pInt)
{
   // Did not initialize pInt buffer before returning!
}

void OutCaller()
{
   int *pInt = new int;
   GoodOutCallee(pInt);
   BadOutCallee(pInt);
   delete pInt;
}
```

A ferramenta de análise de Visual Studio Code valida que o chamador passa um ponteiro não nulo para um buffer `pInt` para e que o buffer é inicializado pela função antes de retornar.

### <a name="example-the-_out_opt_-annotation"></a>Exemplo: a \_anotação\_opcional\_ de saída

`_Out_opt_`é o mesmo que `_Out_`, exceto que o parâmetro pode ser nulo e, portanto, a função deve verificar isso.

```cpp
void GoodOutOptCallee(_Out_opt_ int *pInt)
{
   if (pInt != NULL) {
      *pInt = 5;
   }
}

void BadOutOptCallee(_Out_opt_ int *pInt)
{
   *pInt = 5; // Dereferencing NULL pointer 'pInt'
}

void OutOptCaller()
{
   int *pInt = NULL;
   GoodOutOptCallee(pInt);
   BadOutOptCallee(pInt);
}
```

A análise de Visual Studio Code valida que essa função verifica se há `pInt` NULL antes de ser desreferenciada `pInt` e, se não for NULL, se o buffer for inicializado pela função antes de retornar.

### <a name="example-the-_inout_-annotation"></a>Exemplo: a \_anotação\_ InOut

`_Inout_`é usado para anotar um parâmetro de ponteiro que pode ser alterado pela função. O ponteiro deve apontar para dados inicializados válidos antes da chamada, e mesmo se ele for alterado, ele ainda deverá ter um valor válido no retorno. A anotação especifica que a função pode ler livremente e gravar no buffer de um elemento. O chamador deve fornecer o buffer e inicializá-lo.

> [!NOTE]
> Like `_Out_`, `_Inout_` deve se aplicar a um valor modificável.

```cpp
void InOutCallee(_Inout_ int *pInt)
{
   int i = *pInt;
   *pInt = 6;
}

void InOutCaller()
{
   int *pInt = new int;
   *pInt = 5;
   InOutCallee(pInt);
   delete pInt;
}

void BadInOutCaller()
{
   int *pInt = NULL;
   InOutCallee(pInt); // 'pInt' should not be NULL
}
```

A análise de Visual Studio Code valida que os chamadores passam um ponteiro não nulo para um buffer inicializado para `pInt`, e que, antes `pInt` de retornar, ainda é não nulo e o buffer é inicializado.

### <a name="example-the-_inout_opt_-annotation"></a>Exemplo: a \_anotação\_opt\_ de InOut

`_Inout_opt_`é o mesmo que `_Inout_`, exceto que o parâmetro de entrada pode ser nulo e, portanto, a função deve verificar isso.

```cpp
void GoodInOutOptCallee(_Inout_opt_ int *pInt)
{
   if(pInt != NULL) {
      int i = *pInt;
      *pInt = 6;
   }
}

void BadInOutOptCallee(_Inout_opt_ int *pInt)
{
   int i = *pInt; // Dereferencing NULL pointer 'pInt'
   *pInt = 6;
}

void InOutOptCaller()
{
   int *pInt = NULL;
   GoodInOutOptCallee(pInt);
   BadInOutOptCallee(pInt);
}
```

A análise de Visual Studio Code valida que essa função verifica se há NULL antes de acessar o buffer e, `pInt` se não for NULL, se o buffer for inicializado pela função antes de retornar.

### <a name="example-the-_outptr_-annotation"></a>Exemplo: a \_anotação\_ Outptr

`_Outptr_`é usado para anotar um parâmetro que é destinado a retornar um ponteiro.  O parâmetro em si não deve ser nulo e a função chamada retorna um ponteiro não nulo e esse ponteiro aponta para os dados inicializados.

```cpp
void GoodOutPtrCallee(_Outptr_ int **pInt)
{
   int *pInt2 = new int;
   *pInt2 = 5;

   *pInt = pInt2;
}

void BadOutPtrCallee(_Outptr_ int **pInt)
{
   int *pInt2 = new int;
   // Did not initialize pInt buffer before returning!
   *pInt = pInt2;
}

void OutPtrCaller()
{
   int *pInt = NULL;
   GoodOutPtrCallee(&pInt);
   BadOutPtrCallee(&pInt);
}
```

A análise de Visual Studio Code valida que o chamador passa um ponteiro não nulo para `*pInt`e que o buffer é inicializado pela função antes de retornar.

### <a name="example-the-_outptr_opt_-annotation"></a>Exemplo: a \_anotação\_opcional\_ Outptr

`_Outptr_opt_`é o mesmo que `_Outptr_`, exceto que o parâmetro é opcional — o chamador pode passar um ponteiro nulo para o parâmetro.

```cpp
void GoodOutPtrOptCallee(_Outptr_opt_ int **pInt)
{
   int *pInt2 = new int;
   *pInt2 = 6;

   if(pInt != NULL) {
      *pInt = pInt2;
   }
}

void BadOutPtrOptCallee(_Outptr_opt_ int **pInt)
{
   int *pInt2 = new int;
   *pInt2 = 6;
   *pInt = pInt2; // Dereferencing NULL pointer 'pInt'
}

void OutPtrOptCaller()
{
   int **ppInt = NULL;
   GoodOutPtrOptCallee(ppInt);
   BadOutPtrOptCallee(ppInt);
}
```

A análise de Visual Studio Code valida que essa função verifica se há `*pInt` NULL antes de ser desreferenciada e que o buffer é inicializado pela função antes de retornar.

### <a name="example-the-_success_-annotation-in-combination-with-_out_"></a>Exemplo: a \_anotação\_ de sucesso em combinação \_com out\_

As anotações podem ser aplicadas à maioria dos objetos.  Em particular, você pode anotar uma função inteira.  Uma das características mais óbvias de uma função é que ela pode ser bem-sucedida ou falhar. Mas, assim como a associação entre um buffer e seu tamanho, o C/C++ não pode expressar a função êxito ou falha. Usando a anotação `_Success_` , você pode dizer a aparência do sucesso de uma função.  O parâmetro para a `_Success_` anotação é apenas uma expressão que, quando for verdadeira, indica que a função foi bem-sucedida. A expressão pode ser qualquer coisa que o analisador de anotação possa manipular. Os efeitos das anotações após o retorno da função são aplicáveis somente quando a função é realizada com sucesso. Este exemplo mostra como `_Success_` interage com `_Out_` para fazer a coisa certa. Você pode usar a palavra `return` -chave para representar o valor de retorno.

```cpp
_Success_(return != false) // Can also be stated as _Success_(return)
bool GetValue(_Out_ int *pInt, bool flag)
{
   if(flag) {
      *pInt = 5;
      return true;
   } else {
      return false;
   }
}
```

A `_Out_` anotação faz Visual Studio Code análise para validar que o chamador passa um ponteiro não nulo para um buffer para `pInt`e que o buffer é inicializado pela função antes de retornar.

## <a name="sal-best-practice"></a>Prática recomendada de SAL

### <a name="adding-annotations-to-existing-code"></a>Adicionando anotações a um código existente

SAL é uma tecnologia poderosa que pode ajudá-lo a melhorar a segurança e a confiabilidade do seu código. Depois de aprender o SAL, você pode aplicar a nova habilidade ao seu trabalho diário. No novo código, você pode usar as especificações baseadas em SAL por meio do design; no código mais antigo, você pode adicionar anotações incrementalmente e, assim, aumentar os benefícios sempre que atualizar.

Os cabeçalhos públicos da Microsoft já estão anotados. Portanto, sugerimos que, em seus projetos, você anota primeiro funções e funções de nó folha que chamam APIs do Win32 para obter o máximo benefício.

### <a name="when-do-i-annotate"></a>Quando devo anotar?

Aqui estão algumas diretrizes:

- Anote todos os parâmetros do ponteiro.

- Anote as anotações de intervalo de valor para que a análise de código possa garantir a segurança do buffer e do ponteiro.

- Anote as regras de bloqueio e os efeitos colaterais de bloqueio. Para obter mais informações, consulte [anotando o comportamento de bloqueio](../code-quality/annotating-locking-behavior.md).

- Anote as propriedades do driver e outras propriedades específicas do domínio.

Ou você pode anotar todos os parâmetros para que sua intenção fique mais clara e para facilitar a verificação de que as anotações foram feitas.

## <a name="related-resources"></a>Recursos relacionados

[Blog da equipe de análise de código](https://blogs.msdn.microsoft.com/codeanalysis/)

## <a name="see-also"></a>Confira também

- [Usando anotações de SAL para reduzir defeitos de código do C/C++](../code-quality/using-sal-annotations-to-reduce-c-cpp-code-defects.md)
- [Anotando parâmetros de função e valores de retorno](../code-quality/annotating-function-parameters-and-return-values.md)
- [Anotando o comportamento da função](../code-quality/annotating-function-behavior.md)
- [Anotando estruturas e classes](../code-quality/annotating-structs-and-classes.md)
- [Anotando o comportamento de bloqueio](../code-quality/annotating-locking-behavior.md)
- [Especificando quando e onde uma anotação se aplica](../code-quality/specifying-when-and-where-an-annotation-applies.md)
- [Práticas recomendadas e exemplos](../code-quality/best-practices-and-examples-sal.md)
