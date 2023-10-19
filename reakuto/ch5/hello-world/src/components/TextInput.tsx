import { useRef } from 'react';

const TextInput: React.FC = () => {
	const inputRef = useRef<HTMLInputElement>(null);

	const handleClick = () => {
		inputRef.current?.focus();
	};

	return (
		<div>
			<input type="text" ref={inputRef} />
			<input type="button" value="Focus" onClick={handleClick} />
		</div>
	);
};

export default TextInput;
