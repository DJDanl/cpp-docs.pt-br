---
title: "/ZC:alignedNew (C++ 17 excesso alinhados alocação) | Microsoft Docs"
ms.date: 12/14/2017
ms.technology: cpp-tools
ms.topic: article
f1_keywords: /Zc:alignedNew
dev_langs: C++
helpviewer_keywords:
- /Zc:alignedNew
- Zc:alignedNew
- -Zc:alignedNew
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 1a4d6e801b258697154a4b11c7b5e468c090cc94
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="zcalignednew-c17-over-aligned-allocation"></a>/ZC:alignedNew (C++ 17 excesso alinhados alocação)

Habilitar o suporte para C++ 17 excesso alinhado **novo**, alocação de memória dinâmica alinhada em limites de maiores que o padrão para o tamanho máximo padrão alinhado tipo, **max\_alinhar\_t**.

## <a name="syntax"></a>Sintaxe

> **/ZC:alignedNew**[-]

## <a name="remarks"></a>Comentários

Visual Studio versão 15,5 permite que o compilador e suporte a biblioteca C++ 17 padrão excesso alinhados alocação de memória dinâmica. Quando o **/Zc:alignedNew** opção for especificada, uma alocação dinâmica como `new Example;` respeita o alinhamento do *exemplo* mesmo quando ele é maior do que `max_align_t`, maior alinhamento necessário para todos os tipos fundamentais. Quando o alinhamento do tipo alocado não está mais do que a garantia pelo operador original **novo**, disponível como o valor da macro predefinida  **\_ \_STDCPP\_padrão \_Novo\_ALINHAMENTO\_\_**, a instrução `new Example;` resulta em uma chamada para `::operator new(size_t)` como no C++ 14. Quando for maior que o alinhamento  **\_ \_STDCPP\_padrão\_novo\_ALINHAMENTO\_\_**, em vez disso, obtém a implementação a memória usando `::operator new(size_t, align_val_t)`. Da mesma forma, a exclusão de tipos excesso alinhados invoca `::operator delete(void*, align_val_t)` ou o tamanho excluir assinatura `::operator delete(void*, size_t, align_val_t)`.

O **/Zc:alignedNew** opção está disponível apenas quando [/std:c + + 17](std-specify-language-standard-version.md) ou [/std:c + + mais recente](std-specify-language-standard-version.md) está habilitado. Em **/std:c + + 17** ou **/std:c + + mais recente**, **/Zc:alignedNew** é habilitado por padrão, de acordo com o ISO padrão C++ 17. Se a única razão, você implementa o operador **novo** e **excluir** deve dar suporte a alocações excesso alinhadas, você pode não precisar mais este código em modo C++ 17. Desativar essa opção e reverter para o comportamento de 14 C + + do **novo** e **excluir** quando **/std::c + + 17** ou **/std:c + + mais recente** for especificado, Especifique **/Zc:alignedNew-**. Se você implementar operador **novo** e **excluir** , mas você não está pronto para implementar o operador excesso alinhado **novo** e **excluir** sobrecargas que têm o `align_val_t` parâmetro, use o **/Zc:alignedNew-** opção para impedir que o compilador e a biblioteca padrão gerar chamadas para as sobrecargas excesso alinhadas.

## <a name="example"></a>Exemplo

Este exemplo mostra como operador **novo** e operador **excluir** se comportam quando o **/Zc:alignedNew** opção é definida.

```cpp
// alignedNew.cpp
// Compile by using: cl /EHsc /std:c++17 /W4 alignedNew.cpp
#include <iostream>
#include <malloc.h>
#include <new>

// "old" unaligned overloads
void* operator new(std::size_t size) {
    auto ptr = malloc(size);
    std::cout << "unaligned new(" << size << ") = " << ptr << '\n';
    return ptr ? ptr : throw std::bad_alloc{};
}

void operator delete(void* ptr, std::size_t size) {
    std::cout << "unaligned sized delete(" << ptr << ", " << size << ")\n";
    free(ptr);
}

void operator delete(void* ptr) {
    std::cout << "unaligned unsized delete(" << ptr << ")\n";
    free(ptr);
}

// "new" over-aligned overloads
void* operator new(std::size_t size, std::align_val_t align) {
    auto ptr = _aligned_malloc(size, static_cast<std::size_t>(align));
    std::cout << "aligned new(" << size << ", " <<
        static_cast<std::size_t>(align) << ") = " << ptr << '\n';
    return ptr ? ptr : throw std::bad_alloc{};
}

void operator delete(void* ptr, std::size_t size, std::align_val_t align) {
    std::cout << "aligned sized delete(" << ptr << ", " << size << 
        ", " << static_cast<std::size_t>(align) << ")\n";
    _aligned_free(ptr);
}

void operator delete(void* ptr, std::align_val_t align) {
    std::cout << "aligned unsized delete(" << ptr << 
        ", " << static_cast<std::size_t>(align) << ")\n";
    _aligned_free(ptr);
}

struct alignas(256) OverAligned {}; // warning C4324, structure is padded

int main() {
    delete new int;
    delete new OverAligned;
}
```

Esta saída é típica para versões de 32 bits. O ponteiro valores variar com base em onde o aplicativo é executado na memória.

```Output
unaligned new(4) = 009FD0D0
unaligned sized delete(009FD0D0, 4)
aligned new(256, 256) = 009FE800
aligned sized delete(009FE800, 256, 256)
```

Para obter informações sobre problemas de conformidade no Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **linha de comando** página de propriedades no **C/C++** pasta.

1. Modificar o **opções adicionais** propriedade incluir **/Zc:alignedNew** ou **/Zc:alignedNew-** e, em seguida, escolha **Okey**.

## <a name="see-also"></a>Consulte também

[/ZC (conformidade)](../../build/reference/zc-conformance.md)  
